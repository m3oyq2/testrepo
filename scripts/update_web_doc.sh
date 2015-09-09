#!/bin/bash
#

## Purpose: Jenkins does builds of code and docs
##          This script is for jenkins post build job to run

DOC_BASE="/var/www/site.com/html/AVR"
PROJECT_NAME="MorseTest"

## DOC_BASE must be owned by the jenkins user
## create directory if not there
if
  [ ! -d "${DOC_BASE}/${PROJECT_NAME}" ]
then
  mkdir "${DOC_BASE}/${PROJECT_NAME}"
fi

cp -rp ../doc/html/* ${DOC_BASE}/${PROJECT_NAME}


## copy over htauth file

cp ../auth/.htaccess ${DOC_BASE}/${PROJECT_NAME}/
