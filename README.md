gnublin-ferraris
================

Monitors a power meter by polling a light barrier which observes the power meter's ferraris wheel.
Runs as deamon on the GNUBLIN Embedded Linux board (http://gnublin.embedded-projects.net).

Usage:
* make # either on GNUBLIN or on Host Computer with cross-compiler
* ./gnublin-ferraris

* To provide power meter statistics via lighttpd, enable the cgi module of lighttpd and place cgi-bin/powermeter under /usr/lib/cgi-bin/.
