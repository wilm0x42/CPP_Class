# Multi user IDE! :D

To make working with students on code easier,
I threw together this browser-based IDE.
It allows several people to type in the same
text editor in real time, complete with the
ability to compile the code and see the
console output.

Unfortunately, I was way too
lazy to actually sandbox the running of
applications. Running this software is
actually a huge vulnerability. Oh well :P

_Note: the server expects the folder "run" to exist here.
Thanks, Git :/_

## List of things
* `content/` - Static files to be served
* `run/` - Supposed to exist
* `server.js` - NodeJS web server
* `run_cpp.sh` - Called from server.js to compile and run submitted code.
