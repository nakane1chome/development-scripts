/*
   Simple test program to instanciate and access each device to test compilation.
   SPDX-License-Identifier: Unlicense
*/

#include "{{device.name}}.hpp"
{%- for p in device.peripherals %}
#include "{{p.name}}_mmio_dev.hpp"
{%- endfor%}

int main(void) {
    // Instanciate each peripheral class
{%- for p in device.peripherals %}
   {{p.name}}_dev<base_addr::{{device.name}}::{{p.name}}> {{p.name}}_i;
{%- endfor%}
    // Read and write one register from each peripheral.
{%- for p in device.peripherals %}

    // Peripheral: {{p.name}}
{%- for r in p.registers %}
    // Register: {{r.name}}
    {{p.name}}_i.{{r.name}}.write(1);
    auto {{p.name}}_{{r.name}}_v = {{p.name}}_i.{{r.name}}.read();
    {%- for f in r.fields %}
    // Field : {{f.name}}
    {{p.name}}_i.{{r.name}}.{{f.name}}.write(1);
    auto {{p.name}}_{{r.name}}_{{f.name}}_v = {{p.name}}_i.{{r.name}}.{{f.name}}.read();    
       {%- break %}
    {%- endfor%}
    {%- break %}
{%- endfor%}
{%- endfor%}

}
