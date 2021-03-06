/**
 * @file
 * Test code for mutt_str_remall_strcasestr()
 *
 * @authors
 * Copyright (C) 2019 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define TEST_NO_MAIN
#include "acutest.h"
#include "config.h"
#include "mutt/mutt.h"

struct RemallTest
{
  const char *str;
  const char *expected;
};

void test_mutt_str_remall_strcasestr(void)
{
  // int mutt_str_remall_strcasestr(char *str, const char *target);

  {
    TEST_CHECK(mutt_str_remall_strcasestr(NULL, "apple") == 1);
  }

  {
    TEST_CHECK(mutt_str_remall_strcasestr("apple", NULL) == 1);
  }

  {
    TEST_CHECK(mutt_str_remall_strcasestr(NULL, NULL) == 1);
  }

  // clang-format off
  struct RemallTest remall_tests[] =
  {
    { "",                        ""         },
    { "hello",                   "hello"    },
    { "apple",                   ""         },
    { "aPpLE",                   ""         },

    { "applebye",                "bye"      },
    { "AppLEBye",                "Bye"      },
    { "helloapplebye",           "hellobye" },
    { "hellOAPplEBye",           "hellOBye" },
    { "helloapple",              "hello"    },
    { "hellOAPpLE",              "hellO"    },

    { "appleApplebye",           "bye"      },
    { "AppLEAppLEBye",           "Bye"      },
    { "helloAppLEapplebye",      "hellobye" },
    { "hellOAPplEAppLEBye",      "hellOBye" },
    { "helloappleAppLE",         "hello"    },
    { "hellOAPpLEAPPLE",         "hellO"    },

    { "APpLEAPPLEApplEAPPle",    ""         },
  };
  // clang-format on

  {
    const char *remove = "apple";
    char buf[64];

    for (size_t i = 0; i < mutt_array_size(remall_tests); i++)
    {
      struct RemallTest *t = &remall_tests[i];
      memset(buf, 0, sizeof(buf));
      strncpy(buf, t->str, sizeof(buf));
      TEST_CASE(buf);

      mutt_str_remall_strcasestr(buf, remove);
      TEST_CHECK(strcmp(buf, t->expected) == 0);
    }
  }
}
