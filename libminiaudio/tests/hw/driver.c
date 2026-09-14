#include <miniaudio/miniaudio.h>

#include <stdio.h>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif

static void
data_callback (ma_device *device, void *output, const void *input, ma_uint32 frame_count)
{
  ma_waveform_read_pcm_frames ((ma_waveform *) device->pUserData,
                               output,
                               frame_count,
                               NULL);
  (void) input;
}

int
main (void)
{
  ma_waveform sine;
  ma_waveform_config sine_config;
  ma_device_config device_config;
  ma_device device;

  device_config = ma_device_config_init (ma_device_type_playback);
  device_config.playback.format   = ma_format_f32;
  device_config.playback.channels = 2;
  device_config.sampleRate        = 48000;
  device_config.dataCallback      = data_callback;
  device_config.pUserData         = &sine;

  if (ma_device_init (NULL, &device_config, &device) != MA_SUCCESS)
  {
    fprintf (stderr, "failed to open playback device\n");
    return 1;
  }

  sine_config = ma_waveform_config_init (device.playback.format,
                                         device.playback.channels,
                                         device.sampleRate,
                                         ma_waveform_type_sine,
                                         0.2,
                                         220);
  if (ma_waveform_init (&sine_config, &sine) != MA_SUCCESS)
  {
    fprintf (stderr, "failed to init waveform\n");
    ma_device_uninit (&device);
    return 1;
  }

  if (ma_device_start (&device) != MA_SUCCESS)
  {
    fprintf (stderr, "failed to start playback device\n");
    ma_waveform_uninit (&sine);
    ma_device_uninit (&device);
    return 1;
  }

  printf ("playing sine on %s\n", device.playback.name);
#if defined(_WIN32)
  Sleep (1000);
#else
  sleep (1);
#endif

  ma_device_uninit (&device);
  ma_waveform_uninit (&sine);
  return 0;
}
