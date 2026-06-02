# Bridge Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Decouples an abstraction from its implementation so that the two can **vary independently**.

When an abstraction can be implemented in multiple ways, inheritance is generally employed; however, this approach implies a static binding between the abstraction and its behavior that makes it difficult to extend, modify, and use the abstraction and implementation independently.

Suppose you want to extend a such an inheritance structure with an abstraction: for each available implementation (platform), you must create a class that implements the new interface. Suppose you want to add a new implementation, all existing abstractions must be extended by the new implementation (platform toolkit).

Clients should be able to use abstractions **without commiting** to concrete implementations. Think of platform-dependent implementations that must not clutter/concern client code; that is platform-specific code must be encapsulated in the implementation inheritance hierarchy.

## Applicability

- you want to avoid permanent binding between an abstraction and its implementation; allows for runtime selection/switching.
- both the abstraction and the implementation should be extensible by inheritance. Their interface may be different.
- changing the implementation should not trigger recompilation of the abstraction.
- you want to hide the implementation of an abstraction completely from users.
- there is a large amount of classes that can be split into two hierarchies - *nested generalizations*. Usually, one generalization provides primitives which can be composed by concrete subclasses of the abstraction to obtained the required behavior; e.g.: different operating systems provide incompatible drawing primitives that can be encapsulated in a common interface.
- you want to share an implementation among multiple objects (maybe using reference counting).

## Consequences

- no compile time dependency between interface and implementation. Changing the implementation does not trigger interface recompilation. This is useful when you must ensure compatiblity between different versions of a class library.
- it encourages layering which can lead to better partitioned systems.
- improved extensibility (interface and implementation **individually**).
- transparent implementation details (reference counts, for example).

## Implementation Issues

- when there is a single implementor (implying no interface) constitues a degenerate case of the *bridge* design pattern. However, it can still be useful when changing the implementation must not affect existing clients (*C++ pimpl*).
- if the abstraction knows about all the implementations, it can choose the most suitable implementation itself;
- the abstraction can be default initialized with some implementation which can be changed on demand at runtime;
- instantiating the implementation can be deferred to an *abstract factory* (it promotes decoupling between implementation and abstraction).
- it provides a basis for sharing the implementation by reference counting (*handle-body C++ idiom*).
- you can use multiple inheritance to obtain a degenerate *bridge* design pattern implementation: inherit publicly the interface and privately the implementation; note that this implies runtime binding, hence, tight coupling.
- the *bridge* design pattern is generally used at system design time, while the *adapter* design pattern is applied to systems after they are designed.