//
// Created by janek on 20.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H

#include <StudentRepository.h>
#include <string>
#include <vector>
#include <initializer_list>

namespace academia {
    // zdefiniowane w StudentRepository
//    class Query {
//    public:
//        virtual bool Accept(const Student &student) const =0;
//    };

    class ByFirstName : public Query{
    public:
        ByFirstName(std::string name):firstname_(name) {}
        bool Accept(const Student &student) const override;
    private:
        std::string firstname_;
    };

    class ByLastName : public Query{
    public:
        ByLastName(std::string name):lastname_(name) {}
        bool Accept(const Student &student) const override;
    private:
        std::string lastname_;
    };

    class ByOneOfPrograms : public Query{
    public:
        ByOneOfPrograms(std::initializer_list<std::string> prog_names):program_(prog_names) {}
        bool Accept(const Student &student) const override;
    private:
        std::vector<std::string> program_;
    };

    class ByYearLowerOrEqualTo : public Query{
    public:
        ByYearLowerOrEqualTo(StudyYear year):year_(year) {}
        bool Accept(const Student &student) const override;
    private:
        StudyYear year_;
    };

//    class OrQuery : public Query{
//    public:
//        OrQuery(initializer_list<Query> condit): conditions_(condit) {};
//        bool Accept(const Student &student) const override;
//    private:
//        std::vector<Query> conditions_;
//    };

//    class AndQuery : public Query{
//    public:
//        AndQuery(initializer_list<Query> condit) {
//            for (auto &&item : condit) {
//                conditions_.push_back(item);
//            }
//
//        };
//        bool Accept(const Student &student) const override;
//    private:
//        std::vector<Query> conditions_;
//    };
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H