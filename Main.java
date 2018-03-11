import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

class Tariff {

    static Tariff[] tariffPlans = new Tariff[4];
    
    private int id;
    private String code = new String();
    private String name = new String();
    private double rate;
    private String otherDetails = new String();
    
    static void loadTariffs() {
        
        createObjectAndLoadTariff( 1 , "1" , "Local calls O/N" , 1 , "NIL" );
        
        createObjectAndLoadTariff( 2 , "2" , "other state" , 3 , "valdity-28 days" );
        
        createObjectAndLoadTariff( 3 , "3" , "other nations" , 5 , "NIL" );
        
        createObjectAndLoadTariff( 4 , "4" , "local and S/N" , 0.2 , "valdity-7 days" );
        
    }
    
    static void createObjectAndLoadTariff(int lId, String lCode, String lName, double lRate, String lOtherDetails) {
        
        Tariff object = new Tariff();
        
        object.id = lId;
        object.code = lCode;
        object.name = lName;
        object.rate = lRate;
        object.otherDetails = lOtherDetails;

        tariffPlans[ lId - 1 ] = object;
        
    }
    
    private double computeCallCost(CustomerPhoneCall customerPhoneCallObject) {
        
        long callStartTime, callEndTime, callDuration;
        int callType;
        
        callStartTime = customerPhoneCallObject.getCallStartTime().getTime();
        callEndTime = customerPhoneCallObject.getCallEndTime().getTime();
        callType = customerPhoneCallObject.getCallType();
        
        callDuration = calculateCallDuration( callStartTime , callEndTime );
                
        switch ( callType ) {
            
            case 1:
                return ( tariffPlans[ 0 ].rate * callDuration );
                
            case 2:
                return ( tariffPlans[ 1 ].rate * callDuration );
                
            case 3:
                return ( tariffPlans[ 2 ].rate * callDuration );
                
            case 4:
                return ( tariffPlans[ 3 ].rate * callDuration );
                
        }
        
        return 0;
        
    }
    
    long calculateCallDuration(long lCallStartTime, long lCallEndTime) {
        
        long diff = lCallEndTime - lCallStartTime;
	
		long diffMinutes = diff / (60 * 1000) % 60;
		long diffHours = diff / (60 * 60 * 1000) % 24;
		long diffDays = diff / (24 * 60 * 60 * 1000);
        
        if ( diffHours != 0 )
        
            diffMinutes += ( diffHours * 60 );
            
        if ( diffDays != 0 )
        
            diffMinutes += ( diffHours * 1440 );
            
        return diffMinutes;
        
    }

    public String generateCallMessage(CustomerPhoneCall customerPhoneCallObject) {
        
        double cost;
        long callType;
        String tariffName = new String();
        double tariffRate;
        
        String callMessage = new String();
        
        callType = customerPhoneCallObject.getCallType();
        cost = computeCallCost( customerPhoneCallObject );
        tariffName = tariffPlans[ (int)callType - 1 ].name;
        tariffRate = tariffPlans[ (int)callType - 1 ].rate;
        
        callMessage = "Dear customer, your last call cost is " + cost + "\n" + "You have been charged under the tariff named " + tariffName + "\n" + "Your tariff rate is " + tariffRate + "Rs/min";
        
        return callMessage;
        
    }
    
}

class CustomerPhoneCall {
    
    private String customerNumber = new String();
    private String calledNumber = new String();
    
    private Date callStartTime;
    private Date callEndTime;

    private int callType;
    
    void setCustomerNumber(String custNum) {
        
        customerNumber = custNum;
        
    }
    
    void setCalledNumber(String calledNum) {
        
        calledNumber = calledNum;
        
    }
    
    void setCallStartTime(String startTime) {
        
        try {
            
            callStartTime = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss").parse( startTime );
            
        } catch (Exception e) {
            
            e.printStackTrace();
            
        }
        
    }
    
    void setCallEndTime(String endTime) {
        
        try {
            
            callEndTime = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss").parse( endTime );
            
        } catch (Exception e) {
            
            e.printStackTrace();
            
        }
        
    }
    
    void setCallType(int type) {
        
        callType = type;
        
    }
    
    String getCustomerNumber() {
        
        return customerNumber;
        
    }
    
    String getCalledNumber() {
        
        return calledNumber;
        
    }
    
    Date getCallStartTime() {
        
        return callStartTime;
        
    }
    
    Date getCallEndTime() {
        
        return callEndTime;
        
    }
    
    int getCallType() {
        
        return callType;
        
    }
}

class Main {
    
    public static void main(String args[]) {
        
        CustomerPhoneCall customerPhoneCallObject = new CustomerPhoneCall();
        
        obtainCallDetails( customerPhoneCallObject );
        
        Tariff tariffObject = new Tariff();
        
        tariffObject.loadTariffs();
        
        System.out.print( tariffObject.generateCallMessage( customerPhoneCallObject ) );
        
    }
    
    static void obtainCallDetails(CustomerPhoneCall customerPhoneCallObject) {
        
        Scanner scanner = new Scanner( System.in );
        
        System.out.println( "Enter customer phone number :" );
        customerPhoneCallObject.setCustomerNumber( scanner.nextLine() );
        
        System.out.println( "Enter the number called :" );
        customerPhoneCallObject.setCalledNumber( scanner.nextLine() );
        
        System.out.println( "Enter the call start time(dd-MM-yyyy HH:mm:ss) :" );
        customerPhoneCallObject.setCallStartTime( scanner.nextLine() );
        
        System.out.println( "Enter the call end time(dd-MM-yyyy HH:mm:ss) :" );
        customerPhoneCallObject.setCallEndTime( scanner.nextLine() );
        
        System.out.println( "Choose call type :" );
        System.out.println( "1 Local calls O/N 1.0Rs/min" );
        System.out.println( "2 other state 3.0Rs/min" );
        System.out.println( "3 other nations 5.0Rs/min" );
        System.out.println( "4 local and S/N 0.2Rs/min" );
        customerPhoneCallObject.setCallType( scanner.nextInt() );
        
    }
    
}
