#include "solver.h"

int main()
{
    //std::vector<unsigned int> v = {6, 5, 0, 4, 8, 3, 7, 1, 2};

    unsigned int aman=0, amis=0, aeuc=0, bman=0, bmis=0, beuc=0;
    unsigned int tests_num=1000;

    for (int i=0;i<tests_num;i++){
        Board startBoard, targetBoard;
        startBoard.shuffle();

    //std::cout << "Starting board:\n";
    //std::cout << startBoard << std::endl;

        Node start(startBoard);
        Node target(targetBoard);

        Solver solver1(start, target, Strategy::ASTAR,     Heuristic::MANHATTAN);
        Solver solver2(start, target, Strategy::ASTAR,     Heuristic::MISPLACEMENTS);
        Solver solver3(start, target, Strategy::ASTAR,     Heuristic::EUCLIDEAN);
        Solver solver4(start, target, Strategy::BESTFIRST, Heuristic::MANHATTAN);
        Solver solver5(start, target, Strategy::BESTFIRST, Heuristic::MISPLACEMENTS);
        Solver solver6(start, target, Strategy::BESTFIRST, Heuristic::EUCLIDEAN);

    /*std::cout << "A* Manhattan     " << solver1.solve() << std::endl;
    std::cout << "A* Misplacements " << solver2.solve() << std::endl;
    std::cout << "A* Euclidean     " << solver3.solve() << std::endl;

    std::cout << "BestFirst Manhattan     " << solver4.solve() << std::endl;
    std::cout << "BestFirst Misplacements " << solver5.solve() << std::endl;
    std::cout << "BestFirst Euclidean     " << solver6.solve() << std::endl;*/

        aman+=solver1.solve();
        amis+=solver2.solve();
        aeuc+=solver3.solve();
        bman+=solver4.solve();
        bmis+=solver5.solve();
        beuc+=solver6.solve();

    }

    std::cout << "Average results of " << tests_num << " tests which don't ignore 0:\n";

    std::cout << "A* Manhattan     " << (double)aman/tests_num << std::endl;
    std::cout << "A* Misplacements " << (double)amis/tests_num << std::endl;
    std::cout << "A* Euclidean     " << (double)aeuc/tests_num << std::endl;

    std::cout << "BestFirst Manhattan     " << (double)bman/tests_num << std::endl;
    std::cout << "BestFirst Misplacements " << (double)bmis/tests_num << std::endl;
    std::cout << "BestFirst Euclidean     " << (double)beuc/tests_num << std::endl;

    return 0;
}
