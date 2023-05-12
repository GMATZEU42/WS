#include "student.h"

#include <iostream>

int main()
{
    // ereditary
    people::Student gm("Giacomo", 33, "Unibo");
    gm.printInfo();

    std::cout << "gm alma_mater: " << gm.getAlmaMater() << std::endl;

    // polimorfism
    people::Person* am = new people::Student("Alessia", 0, "Unibo");
    am->printInfo();

    //
    people::Person x = people::Student("X", 33, "Y");
    x.printInfo();

    //  
    auto dFactory = degree::DegreeFactory();
    // case local
    gm.addDegree(dFactory.createDegree(degree::DegreeLevel::PRIMARY, "Scuole Elementari San Domenico Savio", 2000U));
    gm.addDegree(dFactory.createDegree(degree::DegreeLevel::SECONDARY_I, "Scuole Medie San Domenico Savio", 2003U));
    gm.addDegree(dFactory.createDegree(degree::DegreeLevel::SECONDARY_II,  "I.T.C.G. Giovanni Maria Angioy", 2009U, "L'energia nucleare", 74U));
    gm.addDegree(dFactory.createDegree(degree::DegreeLevel::MASTER, "Matematica Unibo", 2018U, "Ricostruzione di mappe MRI da dati sottocampionati", 110U));
    gm.printInfo();
    // case pointer
    dynamic_cast<people::Student*>(am)->addDegree(dFactory.createDegree(degree::DegreeLevel::PRIMARY, "Scuole Elementari Angelo Battelli", 2000U));
    dynamic_cast<people::Student*>(am)->addDegree(dFactory.createDegree(degree::DegreeLevel::SECONDARY_I, "Scuole Medie Angelo Battelli", 2003U));
    dynamic_cast<people::Student*>(am)->addDegree(dFactory.createDegree(degree::DegreeLevel::SECONDARY_II, "Liceo Scientifico A.Einstein", 2009U, "La luce", 100U));
    dynamic_cast<people::Student*>(am)->addDegree(
        dFactory.createDegree(degree::DegreeLevel::MASTER, "Matematica Unibo", 2015U, "Compressed sensing in digital tomosynthesis reconstruction", 110U)
    );
    am->printInfo();
    //

    // free memory
    delete am;
    
    return 0;
}