#include <list>
#include <algorithm>
#include <iostream>
//Most of the Code here was Taken from an External source, But a lot of changes were made to the Algorithm
class coordinates {
public:
    int Position_x, Position_y;
    coordinates( int x = 0, int y = 0 ){
        Position_x = x; Position_y = y;
    }
    bool operator ==( const coordinates & object){
        return object.Position_x == Position_x && object.Position_y == Position_y; }
    coordinates operator +( const coordinates& object ) {
        return coordinates( object.Position_x + Position_x, object.Position_y + Position_y ); }

};
//Below is the class for the Maps, this is where I have layed out the structure of the Map,
//by specifying the coordinates.
class map {
public:
    map() {
        int MapSize[30][30] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1},
            {0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1}, {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},

        };
        //Here we are specifying the hight and the width of the map so then I can,
        //excute the map using nested for loops.
        width = height = 30;
        for( int r = 0; r < height; r++ )
            for( int s = 0; s < width; s++ )
                Maps[s][r] = MapSize[r][s];
    }
    int operator() ( int Position_x, int Position_y ) { return Maps[Position_x][Position_y]; }
    char Maps[30][30];
    int width, height;
};

class node {
public:
    bool operator == (const node& object ) { return pos == object.pos; }
    bool operator == (const coordinates& object ) { return pos == object; }
    bool operator < (const node& object ) { return dist + cost < object.dist + object.cost; }
    coordinates pos, parent;
    int dist, cost;
};

//Start of the A* Algorithm programming, the codes below validates the Neighbouring nodes and Calculates the
//shortest path in between these paths, allowing the enemies to go through the map by taking routes that are the shortest.
class aStar {
public:
    aStar() {
        neighbours[0] = coordinates( -1, -1 ); neighbours[1] = coordinates(  1, -1 );
        neighbours[2] = coordinates( -1,  1 ); neighbours[3] = coordinates(  1,  1 );
        neighbours[4] = coordinates(  0, -1 ); neighbours[5] = coordinates( -1,  0 );
        neighbours[6] = coordinates(  0,  1 ); neighbours[7] = coordinates(  1,  0 );

    }
    // This section of the code is used to calculate the Distance of each positions.
    int calcDist( coordinates& position ){
        int Position_x = end.Position_x - position.Position_x, Position_y = end.Position_y - position.Position_y;
        return( Position_x * Position_x + Position_y * Position_y );
    }

    bool Validation( coordinates & position ) {
        return ( position.Position_x >-1 && position.Position_y > -1 && position.Position_x < Maps.width && position.Position_y < Maps.height );
    }

    bool PointsExisting( coordinates& position, int cost ) {
        std::list<node>::iterator i;
        i = std::find( closed.begin(), closed.end(), position );
        if( i != closed.end() ) {
            if( ( *i ).cost + ( *i ).dist < cost ) return true;
            else { closed.erase( i ); return false; }
        }
        i = std::find( open.begin(), open.end(), position );
        if( i != open.end() ) {
            if( ( *i ).cost + ( *i ).dist < cost ) return true;
            else { open.erase( i ); return false; }
        }
        return false;
    }

    bool fillOpen( node& n ) {
        int stepCost, nc, dist;
        coordinates neighbour;

        for( int x = 0; x < 29; x++ ) {
            stepCost = x < 4 ? 1 : 1;
            neighbour = n.pos + neighbours[x];
            if( neighbour == end ) return true;

            if( Validation( neighbour ) && Maps( neighbour.Position_x, neighbour.Position_y ) != 1 ) {
                nc = stepCost + n.cost;
                dist = calcDist( neighbour );
                if( !PointsExisting( neighbour, nc + dist ) ) {
                    node Maps;
                    Maps.cost = nc; Maps.dist = dist;
                    Maps.pos = neighbour;
                    Maps.parent = n.pos;
                    open.push_back( Maps );
                }
            }
        }
        return false;
    }
//Sorting Algorithm is used here to push the enemy onto the maps path if it is free.
    bool search( coordinates& s, coordinates& e, map& mp ) {
        node n; end = e; start = s; Maps = mp;
        n.cost = 0; n.pos = s; n.parent = 0; n.dist = calcDist( s );
        open.push_back( n );
        while( !open.empty() ) {
            node n = open.front();
            open.pop_front();
            closed.push_back( n );
            if( fillOpen( n ) ) return true;
        }
        return false;
    }

    int path( std::list<coordinates>& path ) {
        path.push_front( end );
        int cost = 1 + closed.back().cost;
        path.push_front( closed.back().pos );
        coordinates parent = closed.back().parent;

        for( std::list<node>::reverse_iterator i = closed.rbegin(); i != closed.rend(); i++ ) {
            if( ( *i ).pos == parent && !( ( *i ).pos == start ) ) {
                path.push_front( ( *i ).pos );
                parent = ( *i ).parent;
            }
        }
        path.push_front( start );
        return cost;
    }

    map Maps; coordinates end, start;
    coordinates neighbours[30];
    std::list<node> open;
    std::list<node> closed;
};

//This function specifies where the starting points and the end points are for the
//enemy to travel.
int main( int argc, char* argv[] ) {
    map Maps;
    coordinates starting, finishing( 29, 29 );
    aStar as;
//The code below allows the terminal to generate a map based on the coordinates and
//positions given on X and Y values.
    if( as.search( starting, finishing, Maps ) ) {
        std::list<coordinates> path;
        int c = as.path( path );
        for( int y = -1; y < 31; y++ ) {
            for( int x = -1; x < 31; x++ ) {
                if( x < 0 || y < 0 || x > 29 || y > 29 || Maps( x, y ) == 1 )
                    std::cout << char(0xdb);
                else {
                    //If it finds the path that is empty then a sorting algorithm will push the enemy
                    //into the map, other wise it will just have a simple (.) character.
                    if( std::find( path.begin(), path.end(), coordinates( x, y ) )!= path.end() )
                        std::cout << "x";
                    else std::cout << ".";
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n\n";
    return 0;
}
