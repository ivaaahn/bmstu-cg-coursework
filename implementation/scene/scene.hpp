//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_HPP__
#define __LAB_03_SCENE_HPP__


#include <memory>
#include <objects/object.hpp>

class Scene {
public:
    Scene();

    ~Scene() = default;

    void add(const std::shared_ptr<Object> &object);

    void remove(const Iterator &it);

    Iterator begin();

    Iterator end();

    [[nodiscard]] ConstIterator begin() const;

    [[nodiscard]] ConstIterator end() const;

    [[nodiscard]] ConstIterator cbegin() const;

    [[nodiscard]] ConstIterator cend() const;

private:
    std::shared_ptr<Object> obj;
};


#endif //__LAB_03_SCENE_HPP__
