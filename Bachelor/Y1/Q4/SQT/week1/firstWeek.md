<link rel="stylesheet" type="text/css" href="../styles.css">

# 1.Effective and systematic software testing

<img src="img/testingWorkflow.png" alt="Effective testing" width="75%">

<span class="term">Property-based testing </span>
<span class="definition"> - assert a specific property</span>
- property-based testing framework runs the same test 100 times, each time with a different random input 

<span class="term">Domain testing </span>
<span class="definition"> - a technique that breaks down the requirements into small parts and use them to derive test cases </span>

### Testing effectively and systematically
<span class="term"> Effective </span>
<span class="definition"> - means we focus on writing the right tests</span>

<span class="term"> Systematic </span>
<span class="definition"> - means that for a given piece of code, any developer should come up with the same test suite.</span>
 
## Principles of software testing 
<span class="important"><span class="exclamation">!</span>
Exhaustive testing is impossible \
<span class="definition"> Therefore, there is a need for effective testing. </span></span>

<span class="important"><span class="exclamation">!</span>
Knowing when to stop testing \
<span class="definition">Our goal should always be to
maximize the number of bugs found while minimizing the resources we spend on finding those bugs.</span>
</span>

<span class="term">Pesticide paradox </span>
<span class="definition"> - every method you use to prevent or find bugs leaves a residue of subtler bugs against which those methods are ineffectual. 

<span class="important"><span class="exclamation">!</span> Testers
must use different testing strategies to minimize the number of bugs left in the software.</span> </span>

<span class="important"><span class="exclamation">!</span> No matter what testing you do, it will never be perfect or enough
<span class="definition"> - As Dijkstra used to say, “Program testing can be used to show the presence of bugs, but
never to show their absence.”</span> </span>

### Verification is not validation
<span class="term"> Absence-of-errors fallacy  </span>
<span class="definition"> - Focusing solely on verification and not on validation.</span>

<span class="important"><span class="exclamation">!</span> Verification is
about having the system right; validation is about having the right system.</span>

## The testing pyramid 
<img src="img/testingPyramid.png" alt="Effective testing" width="75%">

<span class="term"> Unit testing  </span>
<span class="definition"> - Test a single feature of the software, purposefully ignoring the other units of the system.</span>

<img src="img/unitTesting.png" alt="Effective testing" width="75%">


<span class="term"> Integration testing  </span>
<span class="definition"> - Test the integration between our code and external parties.</span>
-  Integration testing aims to test multiple
components of a system together, focusing on the interactions between them instead of testing the system as a whole

<img src="img/integrationTesting.png" alt="Effective testing" width="75%">

<span class="term"> System testing  </span>
<span class="definition"> - Test the entire
system together, including all of its classes, dependencies, database , web services, and whatever other components it may have.</span>

<img src="img/systemTesting.png" alt="Effective testing" width="75%">


# 2.Specification-based testing
<span class="term"> Boundary testing  </span>
<span class="definition"> - making the program behave correctly when inputs are near a boundary.</span>

<span class="term"> On Point  </span>
<span class="definition"> - the point that is on
the boundary.</span>

<span class="term"> Off Point  </span>
<span class="definition"> - the point closest to the
boundary that belongs to the partition the on point does not belong to.</span>

<span class="term"> In Points  </span>
<span class="definition"> - points that make the condition true.</span>

<span class="term"> Out Points  </span>
<span class="definition"> -  points that make the condition false.</span>

# The seven steps of specification-based testing
<img src="img/specificationTests.png" alt="Effective testing">

1.<span class="term"> Understand the requirement, inputs, and outputs  </span>
<span class="definition"> - make an overall idea about what needs to be tested.</span>

2.<span class="term"> Explore the program </span>
<span class="definition"> if you did not write the program yourself, a very good way to determine what it does (besides reading the documentation) is to play with it.</span>

3.<span class="term"> Judiciously explore the possible inputs and outputs, and identify the partitions  </span>

4.<span class="term"> Identify the boundaries  </span>
<span class="definition"> - analyze the boundaries of all the partitions you devised in the previous step.</span>

5.<span class="term"> Devise test cases based on the partitions and boundaries </span>
<span class="definition"> - combine all the partitions in the different categories to test all possible combinations of inputs.</span>

6.<span class="term"> Automate the test cases </span>

7.<span class="term"> Augment the test suite with creativity and experience </span>

<span class="important"><span class="exclamation">!</span>  How far should specification testing go? \
<span class="definition"> If the cost is high, it may be
wise to invest more in testing, explore more corner cases, and try different techniques to ensure quality. But if the cost is low, being less thorough may be good enough. </span></span>


https://cppi.sync.ro/materia/programare_dinamica_0.html

https://catalin.francu.com/Academics/MITclasses.html

http://courses.csail.mit.edu/6.857/2020/handouts

http://www.ai.mit.edu/courses/6.863/