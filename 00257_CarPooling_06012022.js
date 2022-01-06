var carPooling = function(trips, capacity) {
	  
	// given by desciprtion
    TRIP_LENGTH = 1000
    let passengerChange = Array(TRIP_LENGTH+1).fill( 0 );
    
	// Update passenger change for each trip
    for( const [passenger, getOn, getOff] of trips){
        
        passengerChange[getOn] += passenger;
        passengerChange[getOff] -= passenger;
    }
    
    let carLoading = 0;
    
	// Count total passenger for each bus top
    for( let i = 0 ; i < passengerChange.length ; i++ ){
        
        carLoading += passengerChange[i];    
		
		// Reject when the car is overloaded somewhere
        if( carLoading > capacity ){
            return false;
        } 
    }
    
	// Accept only if all trip is safe
    return true;
};

//https://leetcode.com/problems/car-pooling/