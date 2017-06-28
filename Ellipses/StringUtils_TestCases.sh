# Test Driven Development - Shell Script

function startScript()
{
			# Test Name #
	executeTests "TestForEllipses"

	read
}

function checkIfEqual()
{
	if [ "$1" == "$2" ]
	then 
		echo "Pass"
	else
		echo "Fail"
	fi
}

function printTestCaseResult()
{
	echo "$1 Test $2 : $3"
}

function callExecutable()
{
	output_string=$( ./StringUtils.exe -maxlength $maxlength_value -lastnchars $lastnchars_value $string )

	echo $output_string
}

function executeTests()
{
	testnumber=1

	# Compile and generate Executable 
	gcc StringUtilTest.c StringUtils.c -o StringUtils.exe

  #-------------------------- TEST CASE 1 ----------------------------------#
	maxlength_value=12
	lastnchars_value=3
	string="Indonesia"

	expected="Indonesia"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $1 $testnumber $result
  #-------------------------------------------------------------------------#
	((testnumber++))
  

  #-------------------------- TEST CASE 2 -------------------------------------#
	maxlength_value=12
	lastnchars_value=3
	string="Indonesia123"

	expected="Indonesia123"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $1 $testnumber $result
  #----------------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 3 --------------------------------------#
	maxlength_value=12
	lastnchars_value=3
	string="Indonesia1234"

	expected="Indone...234"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $1 $testnumber $result
  #-----------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 4 ---------------------------------#
	maxlength_value=6
	lastnchars_value=0
	string="Indonesia"

	expected="Ind..."

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $1 $testnumber $result
  #------------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 5 ---------------------------------#
	maxlength_value=8
	lastnchars_value=7
	string="Indonesia"

	expected="...nesia"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $1 $testnumber $result
  #------------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 6 ---------------------------------#
	maxlength_value=8
	lastnchars_value=9
	string="Indonesia"

	expected="Error!"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )	

	printTestCaseResult $1 $testnumber $result
  #------------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 7 ----------------------------------#
	maxlength_value=-8
	lastnchars_value=3
	string="Indonesia"

	expected="Error!"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )	

	printTestCaseResult $1 $testnumber $result
  #-------------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 8 ----------------------------------#
	maxlength_value=8
	lastnchars_value=-3
	string="Indonesia"

	expected="Error!"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )	

	printTestCaseResult $1 $testnumber $result
  #-------------------------------------------------------------------------#
}

startScript