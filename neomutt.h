/**
 * @file
 * NeoMutt container for notifications
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

#ifndef MUTT_NEOMUTT_H
#define MUTT_NEOMUTT_H

struct Notify;

/**
 * struct NeoMutt - Container for notifications
 */
struct NeoMutt
{
  struct Notify *notify;
};

extern struct NeoMutt *NeoMutt;

struct NeoMutt *neomutt_new(void);
void neomutt_free(struct NeoMutt **ptr);

#endif /* MUTT_NEOMUTT_H */
