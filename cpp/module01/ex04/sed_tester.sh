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

noArgsErrorTest() {
	testName="$1"

	echo ""
	echo "-------------"
	echo -e "$BOLD$testName:$RESET \"./fsdebut \"\n"
	./fsdebut > /dev/null
  echo -e ""
	singleLetterRead "Press any key to continue..." > /dev/null
	echo ""
}

errorTest() {
	testName="$1"
	fileToModify="$2"
	stringToReplace="$3"
	replacement="$4"

	echo ""
	echo "-------------"
	echo -e "$BOLD$testName:$RESET \"./fsdebut $fileToModify $stringToReplace $replacement\"\n"
	./fsdebut "$fileToModify" "$stringToReplace" "$replacement"
  echo -e ""
	singleLetterRead "Press any key to continue..." > /dev/null
	echo ""
}

# Compiling project
echo "Compiling project..."
make

# Launching tests
echo -e "\n$BOLD # LAUNCH TESTS # $RESET"
launchTest "Normal test" "./tests/test.txt" "top" "bob"
launchTest "Single char" "./tests/test.txt" t b
launchTest "Empty s1" "./tests/test.txt" "" b
launchTest "Empty s2" "./tests/test.txt" t ""
launchTest "top to toalha" "./tests/test.txt" p alha

# Error tests
# echo -e "\n$BOLD # ERROR TESTS # $RESET"
# noArgsErrorTest "no args passed"
# errorTest "missing s1 and s2" "./tests/test.txt"
# errorTest "missing s1 and s2" "./tests/test.txt" "test"
# errorTest "empty file" "" "t" "p"
# errorTest "file not found" "test.txt" "t" "p"
# errorTest "file w/ no permission"

# Clean up
echo "Cleaning binary and .replace test files..."
make fclean
rm ./tests/*.replace
