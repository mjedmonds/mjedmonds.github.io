

WITH A C-MENTALITY AND NO EXCEPTION HANDLING....


///  Supposing I Have The Class Auto
///  I Am Going To Drive To Work...

Car c( "Honda", "Prelude" );
rv = c.openDoor();
if (rv == DOOR_LOCKED || rv == CAR_STOLEN || rv == WRONG_KEYS || rv == WRONG_CAR ) {
   // something bad happened...
}
else {
   rv = c.insertKey();
   if (rv == WRONG_KEYS || rv == KEY_UPSIDE_DOWN || rv == WRONG_CAR ) {
     // something bad happened...
   }
   else {
      rv = c.turnKey();
      if (rv == DEAD_BATTERY || rv == NO_GAS || rv == ASTEROID_HITS_ENGINE || rv == SADDAM_IN_ENGINE) {
         // something bad happened...
      }
      else { 
         rv = c.intoReverse();
         if (rv == CLUTCH_DIED || rv == GEAR_FAILED || rv == FLAT_TIRE || rv == NO_GAS || rv == PARKING_BRAKE_UP) {
	    // something bad happened...
         }
	 else {
	    rv = c.drive();
            if (rv == CLUTCH_DIED || rv == GEAR_FAILED || rv == NO_GAS || rv == NUCLEAR_WAR) {
	       // something bad happened...
 	    }
	    else {
		rv = c.intoFirst();
		if (rv == CLUTCH_DIED || rv == GEAR_FAILED || rv == NO_GAS || rv == SPACE_SHUTTLE_DEBRIS_HITS_WINDSHIELD) {
		   // something bad happened...
		}
		else {
		   // Isn't this approach ridiculous???
		   // I've literally spent so much time checking for errors, that I can't figure
		   // out what my code was actually supposed to do...
		}
	    }
	 }
      }
   }
}



VERSUS


///  Supposing I Have The Class Auto
///  I Am Going To Drive To Work...

Car c( "Honda", "Prelude" );
try {
  c.openDoor();
  c.insertKey();
  c.turnKey();
  c.intoReverse();
  c.drive();
  c.intoFirst();
} catch( OutOfGasError ooge ) {
  // something bad happened...
} catch( WrongKeysError wke ) {
  // something bad happened...
} catch( ClutchDiedError cde ) {
  // something bad happened...
} catch( GearFailedError gfe ) {
  // something bad happened...
} catch( FlatTireError fte ) {
  // something bad happened...
}
