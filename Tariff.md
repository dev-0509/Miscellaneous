Private method

To compute the cost of a call based on time interval and tariff plan, the telecom company wants you write a method in Tariff class which cannot be accessed by any other class directly. This method would actually get wrapped / called by a public method in the tariff class. It wants to ensure that no body is aware of the method in which the call cost computation takes place. Lets implement a private method based on this sequence.

1. Create Tariff class.
2. Create a static array with name "tariffPlans" to hold the basic tariffs of size 4 in Tariff class.
3. Create a static void method in Tariff class "loadTariffs" which will create four tariff Objects and add it to the array.
4. Create class CustomerPhoneCall. 
5. Create a private method computeCallCost in Tariff Class that takes in an object of class "CustomerPhoneCall"  and returns the cost for the call. 
6. Create a public method generateCallMessage in Tariff Class that takes in the an object of class "CustomerPhoneCall", internally calls the private method to obtain the cost, and returns a decorated message String as expected in the problem output.
7. Obtain the call details from the user and call the generateCallMessage in the Tariff Class. 
8.  generateCallMessage() method returns the call rate,call type and  tariff rate as a String(Refer sample output) 
Create a class called  Tariff  with the following private member variables 

Data Type	Variable Name
Integer	id
String	code
String	name
Double	rate
String	otherDetails

Create a class called Customer PhoneCall  with the following private member variables
Data Type	Variable Name
String	customerNumber
String	calledNumber
Date	callStartTime
Date	callEndTime
Tariff	callType
Write appropriate getters & setters for all the classes   
Example:    
Attribute - name   
Method - getName(), setName(String name)   

Create a driver class named   Main   which creates an instance of the above mentioned classes.
 Use setters to set the values to objects and display all details using getters from the main method.

 

We have intiated the system with few classes. Now let us start by creating a class called 'Tariff' to hold the tariff details as mentioned below.

ID Type Code          Name                 Rate                  Other details
1     1               -Local calls O/N    -1Rs/min               NIL
2     2               -other state        - 3Rs/min              valdity-28 days
3     3               -other nations      - 5Rs/min              NIL
4     4               -local and S/N      - 0.2Rs/min            valdity-7 days



Obtain the customer phone call details as shown below and by considering the call start datetime and end datetime,call type code estimates the call cost of that customer by using the private method inside the class tariff. 


Note :

Strictly adhere to the object oriented specifications given as part of the problem statement.
Use the same class names and member variable names.   

 
Sample Input and Output 1: 

Enter customer phone number :
+91-8613234789
Enter the number called :
+91-7456896321
Enter the call start time(dd-MM-yyyy HH:mm:ss) :
05-05-2015 01:09:01
Enter the call end time(dd-MM-yyyy HH:mm:ss) :
05-05-2015 02:08:01
Choose call type :
1 Local calls O/N 1.0Rs/min
2 other state 3.0Rs/min
3 other nations 5.0Rs/min
4 local and S/N 0.2Rs/min
1
Dear customer, your last call cost is 59.0
You have been charged under the tariff named Local calls O/N
Your tariff rate is 1.0Rs/min
