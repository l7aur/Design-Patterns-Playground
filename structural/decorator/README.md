# Decorator Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Attach additional responsibilities to individual objects dynamically. A flexible alternative to subclassing. Clients cannot tell the difference between undecorated and decorated components.

## Applicability

- add/remove responsibilities to individual objects dynamically and transparently.
- when extension by subclassing is impractical (i.e. the amount of variation would generate an explosion of subclasses / the base class is unavailable).

## Consequences

- more flexible than static inheritance: properties can be added multiple times, responsibilities can be mixed, attached and detached at runtime.
- feature-laden classes must be avoided (behavior is added incrementally with decorators). This way, adding new behavior does not expose classes to details unrelated to the responsibilities they are adding (unlike inheritance would).
- a decorator is a transparent enclosure, but the objects itselves are different meaning that object identity is not reliable (a reference to the concrete class must be managed, for example).
- lots of small simliar objects.

## Implementation Issues

- decorator's interface must conform to the component it decorates.
- the abstract class may be useless if you are extending an already existing class hierarchy; the forwarding in the abstract class can be merged in the decorator itself.
- components and decorators must descend from a common, **lightweight** interface. Heavyweight component classes generally means that subclasses pay for features they do not use.
- decorator changes the "skin" while strategy changes the "guts" of classes. Lightweight objects suit decorator, but heavyweight objects are better suited for strategy. Strategies may be lightweight even if the class is heavyweight, they have their own interface (must not conform to the one of the component), but changes are needed in the classes to be extended. With decorator, components know nothing about decorators (transparency), with strategies, components must maintain a reference to them.
- you must maintain references to concrete objects if you need to access its interface.