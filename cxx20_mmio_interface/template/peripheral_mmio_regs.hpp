/*
   Register class and field definition for peripheral {{peripheral.name}}.
   SPDX-License-Identifier: Unlicense
*/

#ifndef {{peripheral.name|upper}}_MMIO_REGS_HPP
#define {{peripheral.name|upper}}_MMIO_REGS_HPP

#include <cstdint>
#include "mmio_device.hpp"
#include "{{peripheral.name}}_mmio_param.hpp"

{%- set compressed_registers = peripheral.registers | compress_register_array %}

namespace mmio_regs {
    /* {{peripheral.description}} */
    namespace {{peripheral.name}} {
        {%- for r_info in compressed_registers %}
           {%- set r_name = r_info.0 %}
           {%- set r = r_info.1 %}
           {%- set count = r_info.2 %}
        /* {{r.description}} */
        template<const std::uintptr_t BASE_ADDR> class {{r_name}} 
            : public mmio_device::reg<BASE_ADDR, 
                                mmio_param::{{peripheral.name}}::{{r_name}}_r> {
            {%- if r.fields %}
            public:
            {%- for f in r.fields %}
            /* {{f.description}} */
            mmio_device::reg_field<BASE_ADDR, 
                             mmio_param::{{peripheral.name}}::{{r_name}}_r,
                             mmio_param::{{peripheral.name}}::{{r_name}}::{{f.name}}_f> {{f.name}};
            {%- endfor %}
            {%- endif %}
        }; /* {{r_name}} */
        {%- endfor %}
    } /* {{peripheral.name}} */
} /* mmio_regs */

#endif // {{peripheral.name|upper}}_DEV_HPP
