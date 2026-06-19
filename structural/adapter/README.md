# Adapter Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Convert the interface of a class into another interface clients expect. Adapter lets classes work together that could not otherwise because of incompatible interfaces.

## Applicability

- you want to use an existing class, but its interface does not match the one you need
- you want to design a class that can cooperate with unrelated or unforeseen classes, that is, classes that do not necessarily have compatible interfaces
- *object-based* you need to use several existing subclasses, but it's impractical to adapt their interface by subclassing every one; Adapt the parent class instead

## Consequences

 - *class-based*
   - adapts by committing to a concrete class; won't work when you need to adapt a class **and** all its subclasses 
   - lets the adapter overwrite the behavior of the adaptee
   - introduces only one object and no additional pointer indirection is needed to reach the adaptee
 - *object-based*
   - allows multiple adaptees (itself and all its subclasses) to work with a single adapter; the addapter can also add functionality
   - makes it harder to overwrite the behavior of the adaptee
- the amount of work the adapter does varies: in one extreme it just converts an interface, in the other uses adapter's operations to provide an entirely new set of operations
- *pluggable adapters* are classes that have built-in interface adaptation, that is they do not make the assumption that other classes see the same interface; it lets us incorporate our classes in existing systems that may expect different interfaces to the classes
- adapters are not transparent to clients by default, *using two-way adapters* fixes this issue (multiple inheritance)

## Implementation Issues

- (`C++`) inherit publicly the target and privately the adaptee
- *pluggable adapters*
  - find a small subset of operations (minimal interface) that any class must implement so that we can do the adaptation
  - all adaptees must implement the minimal interface
    - *abstract operations* define abstract operations in the target class that the adapter implements
    - *delegate objects* forward requests that belong to the minimal interface to other objects that implement the minimal interface (now an individual class)
    - *parameterized adapters* something very specific related to Smalltalk and its blocks