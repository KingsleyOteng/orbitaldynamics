using namespace std;

#define Re              6378.1370

// methods
// store the data
void coordinate_transform::
    setCartesianCoordinates
    (double latitude_box1,
        double longitude_box1)
{
        double R;
    
        R = Re * cos(latitude_box1);
    
        z_coordinate = (Re * sin(latitude_box1));
        y_coordinate = R * sin(longitude_box1);
        x_coordinate = R * cos(longitude_box1);
    
};
