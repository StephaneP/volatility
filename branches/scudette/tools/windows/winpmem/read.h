/**
   This file implement methods for reading through the pmem device.

   Copyright 2012 Michael Cohen <scudette@gmal.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __READ_H
#define __READ_H

#include "winpmem.h"

/* Read a page through the PhysicalMemory device. */
LONG PhysicalMemoryPartialRead(IN PDEVICE_EXTENSION extension,
                               LARGE_INTEGER offset, PCHAR buf, ULONG count);

/* Read a large buffer by concatenating lots of small reads. */
NTSTATUS DeviceRead(IN PDEVICE_EXTENSION extension, LARGE_INTEGER offset,
                    PCHAR buf, ULONG *count,
                    LONG (*handler)(IN PDEVICE_EXTENSION,
                                    LARGE_INTEGER, PCHAR, ULONG)
                    );


/* Actual read handler. */
NTSTATUS PmemRead(IN PDEVICE_OBJECT  DeviceObject, IN PIRP  Irp);

#endif