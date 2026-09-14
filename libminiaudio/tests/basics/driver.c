#include <miniaudio/miniaudio.h>

#include <string.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  ma_uint32 major = 0, minor = 0, revision = 0;
  ma_version (&major, &minor, &revision);
  assert (major == 0);
  assert (minor == 11);
  assert (revision == 25);

  {
    const char *s = ma_version_string ();
    assert (s != NULL);
    assert (strcmp (s, "0.11.25") == 0);
  }

  return 0;
}
