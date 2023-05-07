<link rel="stylesheet" type="text/css" href="../styles.css">

# 3.Structural testing and code coverage

<!-- <img src="img/testingWorkflow.png" alt="Effective testing" width="75%"> -->

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> -->

<span class="term"> Structural testing </span>
<span class="definition"> - Using the structure of the source code to guide testing. </span>

<span class="term"> Understanding Coverage criteria </span>
<span class="definition"> - Means Understanding structural testing techniques </span>

## Steps to follow:
<img src="img/stepsStructuralTesting.png" alt="Effective testing">

1.<span class="term"> Specification-based testing  </span>

2.<span class="term"> Read the implementation </span>
<span class="definition"> - Understand the main coding decisions made by the
developer.</span>

3.<span class="term"> Run the devised test suite with a code coverage tool</span>

4.<span class="term"> For each piece of code that is not covered:</span>
- <span class="definition">Understand why that piece of code was not tested.</span>
- <span class="definition">Decide whether the piece of code deserves a test.</span>
- <span class="definition">If a test is needed, implement an automated test case that covers the missing piece.</span>

5.<span class="term"> Look for other interesting tests you can devise based on the code. </span>

## Code coverage Criteria

<span class="term"> Line Coverage</span>
<span class="definition">- At least one test case that covers the line under test.</span>

<span class="term"> Branch Coverage</span>
<span class="definition">- Takes into consideration the fact that branching instructions make the program behave in different ways, depending how
the instruction is evaluated.</span>

<span class="term"> Condition + Branch Coverage</span>
<span class="definition">- Considers not only possible branches but also each condition of each branch statement.</span>

<span class="term"> Path Coverage</span>
<span class="definition">- Covers all the possible paths of execution of the program.</span>

<span class="important"><span class="exclamation">!</span>While ideally this is the strongest criterion, it is often impossible or too expensive to achieve. </span>

##  Complex conditions and the MC/DC coverage criterion

<span class="important"><span class="exclamation">!</span>Modified condition/decision coverage(MC/DC)<span class="definition"> maximizes the number of bugs they can identify while minimizing the effort/cost of building the test suite. </span></span>
MC/DC explained:
https://www.youtube.com/watch?v=HzmnCVaICQ4

Basically, choose the best combo so you have a pair of independent tests for each part of the condition,
also, the number of paths is 2<sup>n</sup>, and we can do only n+1 in this way.


<span class="term"> Loop boundary adequacy criterion</span>
<span class="definition"> - Criterion used to decide when to stop testing a loop. A test suite satisfies
this criterion if and only if for every loop</span>
- <span class="definition">There is a test case that exercises the loop zero times</span>
- <span class="definition"> There is a test case that exercises the loop once.</span>
- <span class="definition">There is a test case that exercises the loop multiple times.</span>

## Mutation Testing
<span class="term"> Mutation Testing</span>
<span class="definition"> - purposefully inserting a bug in the existing code and checking whether the test suite breaks.</span>

### How pitest mutates things

<img src="img/whatPitestDoes.png" alt="Effective testing">

# 4. Designing contracts
<span class="term"> Contracts </span><span class="definition"> - Clearly establish what the class requires as pre-conditions, what the class provides as post-conditions, and what invariants always hold for the class </span>

## Pre-conditions and post-conditions
<span class="term">Pre-conditions</span><span class ="definition">- Ensure that the input values received by a method adhere to what it requires.</span>

<span class="term">Post-conditions</span><span class ="definition">- Ensure that the method returns what it promises to other methods.</span>

<span class="important"><span class="exclamation">!</span> Strong and weak pre- and post-conditions. (they exist =))) </span> 

## Invariants

<span class="important"><span class="exclamation">!</span> Pre-conditions should hold before a method’s execution, and post-conditions should hold after a method’s execution. Now we move on to conditions that must always hold before and after a method’s execution. </span> 

## Changing contracts, and the Liskov substitution principle

<span class="term">Liskov substitution principle (LSP)</span><span class ="definition">- A subclass may be used as a substitution for a base class without breaking the expected behavior of the system.</span>


