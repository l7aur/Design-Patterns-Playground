# Behavioral Design Patterns Notes

## Notes

Behavioral patterns are concerned with **algorithms** and the **assignment of responsibilities between objects**. They describe *not only objects and classes*, but **patterns of communication** between them too. They shift attention from runtime control flow towards object interconnections.

Behavioral **class** patterns use inheritance to distribute behavior between classes: *template* and *interpreter*.

Behavioral **object** patterns use composition **1.** to describe how groups of peers collaborate to carry on a task no single object can carry only by itself (an important issue here is how peers know about each other); and **2.** to encapsulate behavior in an object and delegate requests to it.

## Overview

| Pattern Name            | Scope  | Brief Description                                                                                                    |
| ----------------------- | ------ | -------------------------------------------------------------------------------------------------------------------- |
| Template                | Class  | breaks down an algorithm in steps; subclasses override steps to achieve different algorithms                         |
| Interpreter             | Class  | implements a grammar as an inheritance hierarchy; the interpreter operates on that hierarchy                         |
| Mediator                | Object | ensures compile time loose coupling between peers that must cooperate to carry on a task                             |
| Chain of Responsibility | Object | ensures run time loose coupling between peers that must cooperate to carry on a task                                 |
| Observer                | Object | defines and maintains dependencies between objects; model-view-controller                                            |
| Strategy                | Object | encapsulates an algorithm, hence allowing runtime flexibility in underlying behavior of an object                    |
| Command                 | Object | encapsulates a request so that it can be passed as a parameter, stored in a history or manipulated in some other way |
| Visitor                 | Object | encapsulates behavior that would be otherwise scattered across classes                                               |
| Iterator                | Object | abstracts the way you access and traverse objects in an aggregate                                                    |