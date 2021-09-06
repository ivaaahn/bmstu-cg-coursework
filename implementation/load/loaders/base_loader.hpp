//
// Created by ivaaahn on 15.06.2021.
//

#ifndef __LAB_03_BASE_LOADER_HPP__
#define __LAB_03_BASE_LOADER_HPP__


class BaseLoader {
public:
    BaseLoader() = default;

    virtual ~BaseLoader() = default;

    virtual void open(const std::string &src_name) = 0;

    virtual void close() = 0;

    virtual void loadEdgesCount(size_t &count) = 0;

    virtual void loadPointsCount(size_t &count) = 0;

    virtual void loadPointCoords(double &x, double &y, double &z) = 0;

    virtual void loadEdge(size_t &p1_id, size_t &p2_id) = 0;
};


#endif //__LAB_03_BASE_LOADER_HPP__
