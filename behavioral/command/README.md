# Command Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

The object that invokes the operation is decoupled from the object that knows how to perform it. The first needs to know just how to issue the request, not how to handle it. Consequently, the same command can be requested from different places (no code duplication) and commands can be replaced at runtime. Combined with a strategy design pattern, it allows for command scripting/chaining.

## Applicability

- commands are an object-oriented replacement for callbacks in procedural languages, i.e. they allow object parameterization with actions to perform
- command objects have a lifetime independent of the requestor, consequently you can specify, queue, and execute requests at different times; if the receiver is address-space-independent, the command can be piped to another process
- allows commands to be undone/redone: `undo()` & `redo()`
- supports logging and crash recovery: `store()`, `load()`
- structures the system around high level operations built on primitives, common in transactional systems

## Consequences

- the invoker object is decoupled from the object that carries on the request
- commands are first-class citizens; the pattern allows for better manipulation and extensibility (no classes must be changed to add new commands)
- commands can be assembled into composites (see composite design pattern)

## Implementation Issues

- commands' behavior varies from barely defining a binding between the receiver and the actions that carry the request to implementing the request by itself (no delegation; use this when there is no suitable receiver, the command must be independent, or when the receiver is unknown). Commands may find their receiver dynamically at runtime if needed
- supporting undo/redo implies storing some state of the receiver: the receiver object, the arguments to the operation that is performed, or any values that are changed by the request. Levels of undo/redo are coupled to the *history list* and its traversal (end-to-beginning vs. beginning-to-end). Commands may need to be copied after they are issued by invokers (and before - *prototypes*/after their execution) to preserve the internal state. If the state in the command never changes there is no need for copying
- hysteresis can generate problems after long sequences of undo/redo-s. This can be mitigated by storing additional information about the state of the system. See *memento* design pattern to see how commands can be granted access to this information without exposing their internals 
- generic programming can be employed to reduce code duplication; pass the `receiver` and the `action` to be executed to a generic class instead of creating multiple similar concrete classes.