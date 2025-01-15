#pragma once

#include "Components.hpp"
#include <string>
#include <tuple>
#include <utility>

class EntityManager;

using ComponentTuple = std::tuple<
    CTransform,
    CShape,
    CCollision,
    CInput,
    CScore,
    CLifespan
>;

class Entity
{
    friend class EntityManager;

    ComponentTuple  m_components;
    bool            m_alive = false;
    size_t          m_id;
    std::string     m_tag = "default";

    Entity(const size_t& id, std::string  tag)
        : m_id(id), m_tag(std::move(tag))
    {
    }

public:

    bool is_Alive() const
    {
        return m_alive;
    }

    void destroy()
    {
        m_alive = false;
    }

    size_t id() const
    {
        return m_id;
    }

    const std::string& tag() const
    {
        return m_tag;
    }

    template <typename T>
    bool has() const
    {
        return get<T>().exists();
    }

    template <typename T>
    T& get()
    {
        return std::get<T>(m_components);
    }

    template <typename T>
    const T& get() const
    {
        return std::get<T>(m_components);
    }

    template <typename T, typename... TArgs>
    T& add(TArgs&&... mArgs)
    {
        auto& component = get<T>();
        component = T(std::forward<TArgs>(mArgs)...);
        component.exists = true;
        return component;
    }

    template<typename T>
    void remove()
    {
        get<T>() = T();
    }


};