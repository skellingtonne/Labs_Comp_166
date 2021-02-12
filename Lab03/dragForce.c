/*
   Lab03: Drag lab
   Description: A C program that computes the height and velocity of a falling object, including the effects of atmospheric drag

   Duncan Stannard
   C0444224
   January 29,2021
*/

//Includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Function Declaration
double get_user_input();
double density(double);

//Constant Variable Declaration
const double g  = 9.80665;


/*
   Main: Print instructions, get user inputs, get calculations from functions and display results
*/

int main(){
   //Declare Variables
   double height,mass,drag_Coef,cs_Area,ts_Size,Fg,Fd,Fnet,accel,p,termVelocity;
   double velocity =0.0,time=0.0;

   // Print User Interface
   printf("~~~~~~Falling Object Velocity Calculator~~~~~~\nPlease Enter the height in meters: ");
   height = get_user_input();
   printf("\nPlease Enter the mass in kg: ");
   mass = get_user_input();
   printf("\nPlease Enter the drag coefficent: ");
   drag_Coef=get_user_input();
   printf("\nPlease Enter the cross-sectional area: ");
   cs_Area=get_user_input();
   printf("\nPlease Enter the time step size: ");
   ts_Size=get_user_input();
   FILE *out_file = fopen("Output.txt","w");

   // Print out top row and start calculations
   fprintf(out_file,"Height: %.2lf mass: %.2lf drag_Coef: %.2lf cs_Area: %.2lf ts_Size: %.2lf ",height,mass,drag_Coef,cs_Area,ts_Size);
   printf("\nTime\tHeight\t\tVelocity\n");
   fprintf(out_file,"\nTime\tHeight\t\tVelocity\n");
   Fg=g*mass; // don't need to recalculate
   printf("%.2lf\t%.2lf\t\t%.2lf\n",time,height,velocity);
   fprintf(out_file,"%.2lf\t%.2lf\t\t%.2lf\n",time,height,velocity);
   /*
      Restrict to 100,000 iterations. Inside loop: Increase time scale and calculate the Density, Drag force, Acceleration, 
      Velocity change, Height Change. Then print out the result to the user. When height is 0 stop
   */
   for(int i=0; i<100000;i++){
      
      time = ts_Size*i;

      p=density(height);
      
      Fd=-0.5f*(drag_Coef*p*cs_Area*pow(velocity,2.0f));
      accel=(Fg+Fd)/mass;

      velocity=velocity+accel*ts_Size;
      height -= velocity*ts_Size;

      if (height<=0){break;}
      printf("%.2lf\t%.2lf\t\t%.2lf\n",time,height,velocity);
      fprintf(out_file,"%.2lf\t%.2lf\t\t%.2lf\n",time,height,velocity);
   }
   // Terminal velocity at sea level calculated using the formula from http://hyperphysics.phy-astr.gsu.edu/hbase/airfri2.html
   termVelocity = sqrt((2*mass*g)/(drag_Coef*density(0.0)*cs_Area));
   printf("\nTheoretical terminal velocity at sea level: %.2lf",termVelocity);
   fprintf(out_file,"\nTheoretical terminal velocity at sea level: %.2lf",termVelocity);
   fclose(out_file);
   return(EXIT_SUCCESS);

}

/*
   Get the user input, check if the input is less than zero
*/

double get_user_input(){
   double temp =0.0f;
   scanf("%lf",&temp);
   if(temp<0.0){
      temp=0.0;
      printf("\nInvalid entry only positive numbers\nNumber has been set to:%.1lf",temp);
      return(temp);
   }
   return temp;
}

/* Density.c
 * Compute the density of dry air in SI units.
 * (Uses the global gravitational constant g).
 *
 * @param altitude Altitude in metres above mean sea level
 *
 * @return Density in SI units
 */
double density(double altitude) {
  const double p0 = 101.325e3; // Sea-level std atmospheric pressure, Pascals
  const double T0 = 288.15;    // Sea-level std temperature, Kelvins
  const double L  = 0.0065;    // Temperature lapse rate, K/m
  const double R  = 8.31447;   // Ideal gas constant, J/(mol.K)
  const double M  = 0.0289644; // Molar mass of dry air, kg/mol
  double p, T;
  T = T0 - L*altitude;
  p = p0 * pow((1 - (L*altitude)/T0), (g*M)/(R*L));
  return p*M/(R*T);
}