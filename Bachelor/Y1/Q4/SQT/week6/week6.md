<link rel="stylesheet" type="text/css" href="../styles.css">

<!-- <img src="img/testingWorkflow.png" alt="Effective testing" width="75%"> -->

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> -->

# 7.Design for Testability

<span class="term"> Testability </span>
<span class="definition"> - How easy it is to write automated tests for the system, class, or method under test.</span>

<span class="important"><span class="exclamation">!</span> Separate infrastructure code
from domain code.</span> 

<span class="term"> Domain </span><span class="definition">- Where the core of the system lies: that is, where all the business rules, logic, entities, services, and similar elements reside. </span>

<span class="term"> Infrastructure</span> <span class="definition"> - Code that handles an external dependency</span>

## Hexagonal Architecture  (Ports and Adapters)
<span class="term"> Ports</span><span class="definition">  - Interfaces that define what the infrastructure can do and enable the application to get information from or send information to something else.<span class="important">They are completely separated from the implementation of the infrastructure.</span></span>

<span class="term"> Adapters </span>
<span class="definition"> - They are the implementations of the ports that talk to the database, web service, and so on.<span class="important">They know how the infrastructure works and how to communicate with it.</span></span>

## Dependency Injection and Controllability

<span class="term"> Controlable </span>
<span class="definition">- You can easily control what the class under test does </span>

<span class="term"> Observable </span>
<span class="definition"> - You can see what is going on with the class under test and inspect its outcome</span>

<span class="term"> </span>
<span class="definition"> </span>