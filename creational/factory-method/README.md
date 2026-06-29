# Factory-Method Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory-method allows a class defer instantiation to subclasses.

## Applicability

- a class cannot anticipate the class of objects it must create
- a class wants its subclasses to specify the objects it creates
- classes delegate responsibility to one or several helpers, and you want to localize the knowledge of which helper subclass is the delegate

## Consequences

- factory methods eliminate the need to bind application-specific classes into the code; the code deals only with product interfaces
- clients need to subclass the `Creator` class just to create a new product
- more flexible than creating an object directly; represents a hook for providing an extended version of an object
- suits well parallel class hierarchies

## Implementation Issues

- three main variations
  - `Creator` is an abstract class and provides no implementation for the factory method (manages additional behavior) → requires subclassing to define an implementation
  - `Creator` is a concrete class that provides default behavior for the factory method (+ additional behavior) → uses factory-method for flexibility: designers of subclasses can change the class of objects their parent class instantiates if necessary (Note: do not call the factory-method in the constructor because when subclassing, the subclass constructor must not use that, if necessary, use accessors that use lazy initialization)
  - `Creator` is an abstract class with default behavior (less common, manages additional behavior, but no default for factory method)
- factory methods can be parameterized
- generic programming can be used to avoid subclassing if only the product the factory method must create varies 