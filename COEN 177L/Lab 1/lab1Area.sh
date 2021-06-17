# Name: Gagan Gupta
# Date: 01/09/2020 
# Title: Lab1 – Rectangle and Circle area
# Description: This program computes the area of a rectangle based on the height and the width of the rectangle and the area of a Circle based on the radius and value of pi
# We obtain the height, width, and radius in real time input from the user
#!/bin/sh

#Output all the files in the folder containing the .sh file in it
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
#Home, User, Path, Pwd, and $$ are all used to get data about the User and the file location of the linux files and the .sh file
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
#The User if statement checks if the user is ggupta and oututs accordingly. The who am I fuction gets the name of the user that is running the code right now.
if [ $user = "ggupta" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi
#areaRectangle() uses a while loop containing the fuctions to get the height and the width and we use a expr to multiple the two to get the area and then we output that.
areaRectangle () {
	response="Yes"
	while [ $response != "No" ]
	do
			echo "Enter height of rectangle: "
			read height
			echo "Enter width of rectangle: "
			read width
			area=`expr $height \* $width`
			echo "The area of the rectangle is $area"
			echo "Would you like to repeat for another rectangle [Yes/No]?"
			read response

	done
}
#areaCirlce() uses a while loop containing the fuctions to get the radius from the user. Pi is alread defined in the start of the function and we use a expr with a bc to multiple the float(pi) and the int(radius squared) to get the area and then we output that.
areaCircle () {
	response="Yes"
	pi=3.1415
	while [ $response != "No" ]
	do
			echo "Enter radius of circle: "
			read radius
			area2=`echo "scale=4; $radius * $radius * $pi" | bc`
			echo "The area of the circle is $area2"
			echo "Would you like to repeat for another circle [Yes/No]?"
			read response

	done
}
areaRectangle
areaCircle
