# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/markbr88/esp/esp-idf/components/bootloader/subproject"
  "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader"
  "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader-prefix"
  "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader-prefix/tmp"
  "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader-prefix/src/bootloader-stamp"
  "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader-prefix/src"
  "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/markbr88/Desarrollo/Progs-ESP32/Proyecto-SIM-Tiro/Intrrup-TX-IR/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
