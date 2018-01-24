#!/bin/bash

cat htmlparts/header.html > output.html
nodejs ./index.js >> output.html
cat htmlparts/footer.html >> output.html
sed -i 's/^.*SET.*$/<\/h2>/' output.html