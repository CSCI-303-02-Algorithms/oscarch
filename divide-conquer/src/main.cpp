#include <iostream>
#include <vector>
#include <tuple>
#include <comparator/CoordinateYXComparator.h>
#include <algorithms/QuickSortGeneric.h>
#include <algorithms/QuickSortGenericWithComparator.h>
#include "utilities/ArrayUtilities.h"

using namespace std;

/*
 * We create an alias (ClosestPointsResult) for the result of the closest pair algorithm
 *
 * ClosestPointsResult is a tuple of three elements:
 * 1. The first point in the pair of closest points
 * 2. The second point in the pair of closest points
 * 3. The distance between the points
 */
typedef tuple<Coordinate, Coordinate, double> ClosestPointsResult;

//-----------------------------------------------
//function declarations. See their implementation below to know about their API specification.

ClosestPointsResult *closestPoints(vector<Coordinate> &points);

ClosestPointsResult *closestPoints(vector<Coordinate> &pointsByX, vector<Coordinate> &pointsByY, int left, int right);

double computeDistance(Coordinate p1, Coordinate p2);

void runAlgorithm(vector<Coordinate> &points);

vector<Coordinate> readPoints();

//-----------------------------------------------

int main() {

    //read the points from the "coordinates.txt" file
    vector<Coordinate> filePoints = readPoints();

    //list of test cases
    vector<vector<Coordinate>> testCases{
            vector<Coordinate>(), //empty vector of points
            vector<Coordinate>{Coordinate(3, 3)}, //just one point
            vector<Coordinate>{Coordinate(3, 3), Coordinate(3, 1)}, //just two points
            vector<Coordinate>{Coordinate(3, 3), Coordinate(3, 20), Coordinate(3, 1)}, //p1 and p3 are the closest
            vector<Coordinate>{Coordinate(3, 113), Coordinate(3, 20), Coordinate(3, 1)}, //p2 and p3 are the closest
            vector<Coordinate>{Coordinate(3, 113), Coordinate(3, 20), Coordinate(3, 1001)}, //p1 and p2 are the closest
            filePoints, //all the points from the file

            //TODO: uncomment these lines once the function that reads the points from the file is correctly implemented
            //vector<Coordinate>(filePoints.begin(), filePoints.begin() + 10), //the first 10 points from the file
            //vector<Coordinate>(filePoints.begin(), filePoints.begin() + 20), //the first 20 points from the file
            //vector<Coordinate>(filePoints.begin(), filePoints.begin() + 30) //the first 30 points from the file
    };

    //for each test case, run the algorithm
    for (auto testPoints: testCases) {
        runAlgorithm(testPoints);
        cout << "-----------------" << endl;
    }

    return 0;
}

/*
 * Run the closest-points algorithm on the input vector of points and
 * prints the vector and the algorithm output on the terminal
 */
void runAlgorithm(vector<Coordinate> &points) {

    //print the input
    cout << "Input points: " << points.size() << endl;
    ArrayUtilities<Coordinate>::printArray(points);

    //run the algorithm and return the closest points
    ClosestPointsResult *clsPoints = closestPoints(points);

    //print the output
    cout << "Closest points:" << endl;
    if (clsPoints != nullptr) {

        //we use the get<i> function on the tuple to get the i-th element from the tuple
        auto point1 = get<0>(*clsPoints);
        auto point2 = get<1>(*clsPoints);
        double distance = get<2>(*clsPoints);

        cout << point1.toString() << " - " << point2.toString() << endl
             << "distance: " << distance << endl;
    } else {
        cout << "Undefined for the input!" << endl;
    }
}

/*
 * Function that returns the closest points in the provided list of points.
 */
ClosestPointsResult *closestPoints(vector<Coordinate> &points) {

    //sort the points by the x- and y-coordinates using quicksort
    vector<Coordinate> sortedPointsByX = QuickSortGeneric<Coordinate>(points).sort();
    vector<Coordinate> sortedPointsByY = QuickSortGenericWithComparator<Coordinate>(points,
                                                                                    new CoordinateYXComparator()).sort();
    //call the recursive function that implements the closest points algorithm
    return closestPoints(sortedPointsByX, sortedPointsByY, 0, sortedPointsByX.size() - 1);
}


/*
 * Recursive function that implements and runs the closest-points algorithm on the provided lists of points.
 *
 * The left and right indices indicate the portion of the lists that will be processed by the algorithm at each recursive step,
 * i.e., the algorithm returns the closest points within that portion only.
 *
 * Input:
 * pointsByX: list of points sorted by the x-coordinate
 * pointsByY: the same list of points, but sorted by the y-coordinate
 * left: the index that indicates the start of the sublist to be processed
 * right: the index that indicates the end of the sublist to be processed
 *
 * Output:
 * The closes points (and their distance) or nullptr if the sublists (as defined by left and right) have less than 2 points
 */
ClosestPointsResult *closestPoints(vector<Coordinate> &pointsByX, vector<Coordinate> &pointsByY, int left, int right) {

    //IMPORTANT: Always use the left and right indices in the code below.
    //Remember that they determine the sublist of points that needs to be processed

    //-----------------------------------------
    //these are the base cases

    int size = right - left + 1; //size of the sublist to be processed
    if (size < 2) return nullptr; //there is no solution for this case

    //if there are only two points, just return them and their distance
    if (size == 2) {
        //TODO: write the code for this case
        return nullptr;
        //return new ClosestPointsResult(p1, p2, distance);
    } else {
        //if there are only three points, compare their distance directly and determine/return the closest pair
        if (size == 3) {
            //TODO: write the code for this case
            return nullptr;
        }
    }

    //-----------------------------------------
    //determine the middle index that divides the points into halves and run the current function recursively on each half

    //TODO: write code here...

    //-----------------------------------------
    //determine the closest pair between the closest pairs from both halves (returned by the recursive calls)
    //save the "delta" (i.e., the minimum distance) from the distance of both closest pairs of points

    //TODO: write code here...
    ClosestPointsResult *closestPair = nullptr;
    double delta = -1;

    //-----------------------------------------
    //filter the points whose x-coordinate fall within the middle "2*delta" strip
    //(i.e., points that are "delta"-distance apart from the middle point)

    //TODO: write code here...

    //-----------------------------------------
    //process the points in middle strip:
    //for each point in the strip, starting from the one with the lowest y-coordinate, compute its distance with
    //the next 7 points.
    //if that distance is smaller than the "delta" distance, update "delta" and also the closest points to be returned

    //TODO: write code here...

    //return the closest points and their distance
    return closestPair;

}

/*
 * Computes the Euclidean distance between the two provided points
 */
double computeDistance(Coordinate p1, Coordinate p2) {
    //TODO: write code here...
    return -1;
}

/*
 * Function that reads the points from the file "../data/coordinates.txt"
 */
vector<Coordinate> readPoints() {

    string filePath = "../data/coordinates.txt";
    auto coordinates = vector<Coordinate>();

    //TODO: write the code to read the file into the coordinates vector
    //you can reuse code from previous assignments to do so

    return coordinates;
}

