# Strategy Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Make algorithms in a family interchangeable. It allows algorithm variation independently of clients.

## Applicability

- related classes differ only in behavior.
- algorithm variation is required.
- algorithms use data that clients must not worry about.
- a class defines many behaviors: conditional statements that alter default flow; move related branches in separate classes.

## Consequences

- inheritance hierarchies that factor common functionalities.
- alternative to subclassing; direct inheritance tighlty couples the algorithm (behavior) to the context (class); the strategy design pattern does the opposite.
- conditional statements are removed (recurring conditional statements indicate the need of strategy).
- variation in behavior implementation (same behavior, different time-space complexity).
- clients must understand the differences between strategies; do not use strategy if the variation in behavior is meaningless to clients.
- the strategy interface generates communication overheads especially if not all parameters are required by each concrete strategy.
- strategy pattern increases the number of objects; this implicit overhead can be mitigated if any state associated with a concrete strategy is managed by the context -> all strategies are stateless. Consequently, the strategy objects can be shared across the system (see Flyweight Design Pattern, usually strategies are great flyweights).

## Implementation Issues

- concrete strategies must be granted access to all relevant resources in the context:
    - passing data to methods: *communication overhead* some parameters may not be required by some concrete strategies.
    - passing `this`: tighter coupling, worse encapsulation as context must extend its interface with getters/setters.
- strategies implemented in generic programming iff no runtime strategy selection (behavior does not change post compilation) and compile time strategy selection (behavior can be injected at compile time); implies static binding, thus tight coupling, but increased efficiency.
- strategies can be optional if a default behavior exists.