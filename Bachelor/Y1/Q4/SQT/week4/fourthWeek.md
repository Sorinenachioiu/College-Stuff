<link rel="stylesheet" type="text/css" href="../styles.css">

<!-- <img src="img/testingWorkflow.png" alt="Effective testing" width="75%"> -->

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> -->

# 6. Test Doubles and Mocks

<img src="img/whyTestMocks.png" alt="Why to use test mocks ?">

<span class="term"> Test doubles </span>
<span class="definition"> - Create an object to
mimic the behavior of component B <span class="important">(“it looks like B, but it is not quite B” (Slim Shady - 2000)) </span></span>

Advantages of simulating the behavior of other objects:
- <span class="term"> More control </span>
<span class="definition"> - We can tell these fake objects what to do</span>
- <span class="term"> Simulations are faster </span>
<span class="definition"> - It will return what it was configured to return, and it will cost nothing in terms of time</span>
- <span class="term"> Developers are enabled to reflect on how classes should interact with each other </span>

## Dummies, fakes, stubs, spies and mocks

<span class="term"> Dummy Objects </span>
<span class="definition"> - Passed to the class under test but never used. </span>

<span class="term"> Fake Objects </span>
<span class="definition"> - Real working implementations of the class they simulate. Hovewever, they do the same task in a simpler way.</span>

<span class="term"> Stubs </span>
<span class="definition"> - Hard-coded answers to the calls performed during the test. </span>

<span class="term"> Mocks </span>
<span class="definition"> - Act like stubs in the sense that you can configure how they reply if a method is called. But, they also save all the interactions and allow you to make assertions afterward.</span>

<span class="term"> Spies </span>
<span class="definition"> - Wrap themselves around the real object and observe its behavior. Recording all the interactions with the underlying object we are spying on. </span>

## Mockito 
<img src="img/mockitoImportantMethods.png" alt="Why to use test mocks ?">

## When to mock?

Pragmatically, developers often mock or stub the following types of dependencies:
- <span class="term"> Dependencies that are too slow </span>
- <span class="term"> Dependencies that communicate with external infrastructure </span>
- <span class="term"> Cases that are hard to simulate </span> <span class="definition"> - If we want to force the dependency to behave in a hard-to-simulate way, mocks or stubs can help </span>

On the other hand, developers tend not to mock or stub the following dependencies:
- <span class="term">  Entities </span> 
- <span class="term">  Native libraries and utility methods </span> 
- <span class="term"> Things that are simple enough </span> 

## Mock Example
<img src="img/mockExample.png" alt="Mock example">

## Nice to know mokito verify
<img src="img/verify.png" alt="Mock example">