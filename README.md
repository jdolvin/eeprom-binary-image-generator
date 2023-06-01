# EEPROM binary image generator

-------------------------------------------

#### This is a simple tool to generate binary images to burn onto EEPROMs using a programmer such as the TL866II+.

--------------------------------------------

Currently, it contains a single function in `main.cpp` that generates the binary image
required for the output register on [beneater's 8-bit computer](https://eater.net/8bit).

I used [beneater's Arduino code ](https://github.com/beneater/eeprom-programmer) to determine the correct hex values to
use.

--------------------------------------------


## Notes

- Pre-generated binary images are available here:
    - [Common Cathode 7 Segment Display](https://github.com/jdolvin/eeprom-binary-image-generator/releases/tag/v0.1-alpha-cathode)
    - [Common Anode 7 Segment Display (**UNTESTED**)](https://github.com/jdolvin/eeprom-binary-image-generator/releases/tag/v0.1-alpha-anode)

- The code itself is a work in progress. I am only including it so that you can see how the binary images are generated, or, if you want to contribute to the project.

This code is [GPLv3 Licensed](https://www.gnu.org/licenses/gpl-3.0.html).

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

--------------------------------------------

## To do:

- [ ] Release a command-line executable
- [ ] Optimize code & add additional functions

