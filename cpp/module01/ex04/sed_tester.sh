#!/bin/bash

GREEN='\033[0;32m'
BLUE='\033[0;34m'
BOLD='\033[0;1m'
RESET='\033[0m'

singleLetterRead() {
	text="$1"

	read -n1 -s -r -p "$text" key
	echo "$key"
}

launchTest() {
	testName="$1"
	fileToModify="$2"
	stringToReplace="$3"
	replacement="$4"

	echo ""
	echo "-------------"
	echo -e "$BOLD$testName:$RESET \"./fsdebut $fileToModify $stringToReplace $replacement\"\n"
	./fsdebut "$fileToModify" "$stringToReplace" "$replacement" > /dev/null
	echo -e "$BLUE""Original file: $RESET"
	/bin/cat "$fileToModify"
	echo -e "\n$GREEN""Modified file: $RESET"
	/bin/cat "$fileToModify".replace
  echo -e ""
	singleLetterRead "Press any key to continue..." > /dev/null
	echo ""
}

# Compiling project
echo "Compiling project..."
make

# Launching tests
launchTest "Normal test" "./tests/test.txt" "top" "bob"

# Clean up
echo "Cleaning binary and .replace test files..."
make fclean
rm ./tests/*.replace
