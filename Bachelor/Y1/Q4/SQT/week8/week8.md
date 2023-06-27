<link rel="stylesheet" type="text/css" href="../styles.css">

<!-- <img src="img/testingWorkflow.png" alt="Effective testing" width="75%"> -->

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> -->

# 9.Writing Larger tests

## When to larger tests:
- <span class="term">When you have exercised each class individually, but the overall behavior is composed of many classes, and you want to see them work together</span>
- <span class="term">The class you want to test is a component in a larger plug-and-play architecture</span>

## The five guidelines for designing SQL tests:
- <span class="term"> Adopting modified condition/decision coverage (MC/DC) for SQL conditions </span>
- <span class="term"> Adapting MC/DC for tackling nulls </span>
- <span class="term"> Category-partitioning selected data </span>
    - <span class="definition"> Rows that are retrieved  </span>
    - <span class="definition"> Rows that are merged  </span>
    - <span class="definition"> Rows that are grouped  </span>
    - <span class="definition"> Rows that are selected in a subquery—  </span>
    - <span class="definition">Values that participate in aggregate functions  </span>
    - <span class="definition">Other expressions  </span>
- <span class="term"> Checking the outputs </span>
- <span class="term"> Checking the database constraints </span>

## Writing automated tests for SQL queries

#### Steps:
- establish a connection with the database
- make sure the database is in the right initial state
- execute the SQL query 
- check the output

#### When testing with a real database, we must ensure a clean state:
- <span class="term">Before the test runs</span><span class="definition"> we open the database connection, clean the database, and (optionally) put it in the state we need it to be in before executing the SQL query under test. </span>
- <span class="term"> After the test runs</span><span class="definition"> we close the database connection.</span>

## Selenium testing
<span class="term"> Page objects (POs) </span>
<span class="definition"> - Help us write more maintainable and readable web
tests. The idea of the Page Object pattern is to define a class that encapsulates all the
(Selenium) logic involved in manipulating one page (long story short we define a class per page so that we can easily go through multiple pages)</span>
 
 <span class="important"><span class="exclamation">!</span> Doing a base page object is a good practice ( basically do an abstract class that encapsulatess the common parts of every future PO )</span>

 
# 10.Test code quality

## Principles of maintainable test code

- <span class="term"> Tests should be fast</span>
- <span class="term"> Tests should be cohesive, independent, and isolated</span>
- <span class="term"> Tests should have a reason to exist</span>
- <span class="term"> Tests should be repeatable and not flaky</span>
    - <span class="term">flaky </span>
<span class="definition"> -sometimes pass and sometimes fail, without any changes in the system or test code.</span>
        - Reasons to be flaky:
            - Because it depends on external or shared resources
            - Due to improper time-outs
            - Because of a hidden interaction between different test methods
    - <span class="term">repeatable test</span>
<span class="definition"> -gives the same result no matter how many times it is executed.</span>
- <span class="term"> Tests should have strong assertions</span>
- <span class="term"> Tests should break if the behavior changes</span>
- <span class="term"> Tests should have a single and clear reason to fail</span>
- <span class="term"> Tests should be easy to write</span>
- <span class="term"> Tests should be easy to read</span>
- <span class="term"> Tests should be easy to change and evolve</span>

## Test data builder
<span class="term"> Test data builder </span>
<span class="definition"> helps us create test scenarios by providing a clear and
expressive API. (The trick that allows methods to be chained is to return the
class in the methods (methods return this), as shown in the following listing)</span>
<img src="img/Test data Builder.png" alt="Effective testing">

## Test smells

<span class="term"> code smell </span><span class="definition">- indicates symptoms that may indicate deeper problems in the system’s source code</span>

### List of several well-known test smells:
- <span class="term"> Excessive duplication</span>
- <span class="term"> Unclear assertions</span>
- <span class="term"> Bad handling of complex or external resources</span>
- <span class="term"> Fixtures that are too general</span>
    - <span class="term"> fixture </span><span class="definition"> - the set of input values used to exercise the component under test</span>
- <span class="term"> Sensitive assertions</span><span class="definition"> - a bad assertion may also cause a test to fail when it should not </span>