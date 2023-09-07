#!/bin/bash

usage="Usage: $(basename $0) PROJECT_NAME"

[[ "$#" -eq 1 ]] || (echo "$usage"; exit 1)

project_name="$1"

echo "Preparing template"
gsed -i "s/CPP-PROJECT-TEMPLATE/"$project_name"/g" CMakeLists.txt || (echo "Failed"; exit 1)
gsed -i "s/CPP-PROJECT-TEMPLATE/"$project_name"/g" README.md || (echo "Failed"; exit 1)
echo "Finish"
exit 0
