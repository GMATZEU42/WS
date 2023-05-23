
 #pragma once

#include <string>
#include <map>

namespace degree
{
    enum class DegreeLevel
    {
        NONE,
        PRIMARY,
        SECONDARY_I,
        SECONDARY_II,
        MASTER,
        PHD
    };

    class Degree
    {
    public:
        Degree(const std::string name = "", const unsigned int year = 0U, DegreeLevel level = DegreeLevel::NONE) : m_name(name), m_year(year), m_level(level) {};
        ~Degree() {};
        virtual void printDegree();
    private:
        std::string m_name = "";
        unsigned int m_year = 0U;
        DegreeLevel m_level = DegreeLevel::NONE;
        std::map<DegreeLevel, std::string> m_levelMap{
            {DegreeLevel::NONE, "No degree"},
            {DegreeLevel::PRIMARY, "Primary"},
            {DegreeLevel::SECONDARY_I, "Secondary I"},
            {DegreeLevel::SECONDARY_II, "Secondary II"},
            {DegreeLevel::MASTER, "Master"},
            {DegreeLevel::PHD, "Phd"},
        };
    };

    class Phd : public Degree
    {
    public:
        Phd(std::string name, unsigned int year, std::string thesis, unsigned int vote) : Degree(name, year, DegreeLevel::PHD), m_thesis(thesis), m_vote(vote) {};
        ~Phd() {};
        void printDegree() override;
    private:
        std::string m_thesis;
        unsigned int m_vote = 0U;
    };

    class Master : public Degree
    {
    public:
        Master(std::string name, unsigned int year, std::string thesis, unsigned int vote) : Degree(name, year, DegreeLevel::MASTER), m_thesis(thesis), m_vote(vote) {};
        ~Master() {};
        void printDegree() override;
    private:
        std::string m_thesis;
        unsigned int m_vote = 0U;
    };

    class SecondaryII : public Degree
    {
    public:
        SecondaryII(std::string name, unsigned int year, std::string thesis, unsigned int vote) : Degree(name, year, DegreeLevel::SECONDARY_II), m_thesis(thesis), m_vote(vote) {};
        ~SecondaryII() {};
        void printDegree() override;
    private:
        std::string m_thesis;
        unsigned int m_vote = 0U;
    };

    class SecondaryI : public Degree
    {
    public:
        SecondaryI(std::string name, unsigned int year, unsigned int vote) : Degree(name, year, DegreeLevel::SECONDARY_I), m_vote(vote) {};
        ~SecondaryI() {};
        void printDegree() override;
    private:
        unsigned int m_vote = 0U;
    };

    class Primary : public Degree
    {
    public:
        Primary(std::string name, unsigned int year) : Degree(name, year, DegreeLevel::PRIMARY) {};
        ~Primary() {};
        void printDegree() override;
    };

    class DegreeFactory
    {
    public:
        Degree* createDegree(const DegreeLevel degreeLevel, const std::string name = "", const unsigned int year = 0U, const std::string thesis = "", const unsigned int vote = 0U);
    };
}

