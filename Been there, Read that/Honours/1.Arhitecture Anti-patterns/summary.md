# Architecture Anti-patterns: Automatically Detectable Violations of Design Principles

<link rel="stylesheet" type="text/css" href="../styles.css">

<!-- <img src="img/testingWorkflow.png" alt="Effective testing" width="75%"> -->

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> -->

### Things to be shown in the study:
- files involved in these architecture anti-patterns are more error-prone and change-prone
- the more anti-patterns a file is involved in, the more error-prone and change-prone it is
- while all of our defined architecture anti-patterns contribute to file’s error-proneness
and change-proneness, Unstable Interface and Crossing contribute the most by far

# 1.Introduction
<span class="term"> Architecture anti-patterns </span>
<span class="definition"> - Connections among files that violate design principles and impact bug-proneness and change-proneness</span>

### The six architecture anti-patterns:
- <span class="term"> Unstable Interface </span> <span class="definition"> - if influential files have high change rates, then multiple files depending on them have to be changed as a consequence </span>
<span class="important"><span class="exclamation">!</span> An influential interface with many dependents should remain stable. </span> 
- <span class="term"> Modularity Violation Groups </span> <span class="definition"> - A set of modularity violation file pairs (two files without structural relations but changed together frequently in revision history)  </span>
<span class="important"><span class="exclamation">!</span> Truly independent modules should evolve independently </span> 
- <span class="term"> Unhealthy Inheritance Hierarchy </span> <span class="definition"> - This anti-pattern identifies the violation of the Liskov Substitution principle or Dependency Inversion Principle. This anti-pattern includes cases where the parent class depends on one or more of  this subclasses, or the client of an inheritance hierarcy depends on both the parent class and its children. These cases undermine the objective of an inheritance hierachy to enable polymorphism => this structure propagates bugs and changes to files that depend on this inheritance hierarchy. </span> 
- <span class="term"> Crossing </span> <span class="definition"> - A file that has both high fan-in and high fan-out, and changes often together with its dependents and the files it depends on, is often at the center of maintenance activities. Since files involved in this anti-pattern form a cross shape in a Design Structure Matrix, we call it Crossing.  </span>
- <span class="term"> Clique </span> <span class="definition"> - Cyclic dependency is a well-know design problem. Instead of detecting pair-wise cycles. Files in each Clique instance are tightly coupled with one or more dependency cycles  </span>
<span class="important"><span class="exclamation">!</span> Clique is a set of files that form a strongly connected graph with direct or indirect cycles among files. </span> 
- <span class="term"> Package Cycle </span> <span class="definition"> - Dependency cycles between packages violates the basic design principle of forming a hierarchical structure. </span>
<span class="important"><span class="exclamation">!</span> Changes to a file in one package often cause unexpected changes to files in other packages due to the cycle of dependencies between them. </span> 

### Research questions
- <span class="term"> RQ1</span> <span class="definition"> Do the files involved in architecture anti-pattern consume significantly more maintenance effort than other files in a project? </span>
- <span class="term"> RQ2</span> <span class="definition">  If a file is involved in greater numbers of architecture anti-patterns, is it more error-prone and/or change-prone?
</span>
- <span class="term"> RQ3</span><span class="definition"> Do different types of architecture anti-patterns have different impacts on a file’s overall error-proneness and change-proneness?</span>

# 2.Background

<span class="term"> Design Rule Theory </span>
- <span class="definition"> should be structured by design rules and independent modules. </span>
- <span class="definition"> design rules are often manifested as the important design decisions, which decouple the rest of the system into independent modules </span>
- <span class="definition"> a design rule is typically manifested as
an interface or abstract class </span>
- <span class="definition"> if a Strategy Pattern is implemented, then the strategy interface is considered as the design rule which decouples the context and concrete strategies into independent modules </span>

<span class="term"> Design Rule Hierarchy (DRH) </span>
- <span class="definition"> clusters the file relation of a system into a hierarchical structure. </span>
- <span class="definition"> within such a hierarchy, files in layer L<sub>i</sub> should only depend on files in the higher layers, L<sub>i−1</sub> to L<sub>1</sub>, and files in layer L<sub>i</sub> should not depend on files in the lower layers, L<sub>i+1</sub> to L<sub>n</sub>. Hence files in the first layer, L<sub>1</sub>, should contain most influential interfaces or abstract classes, which do not depend on files in other layers.</span>
- <span class="definition"> files in the same layer are decoupled into a set of modules that are mutually independent from each other. Thus the changes, addition, even replacement to a module will not influence other modules within the same layer</span>
- <span class="definition"> independent modules in the bottom layer of a design rule hierarchy are most valuable, because changes to these modules will not affect the rest of the system </span>

<span class="term"> Design Structure Matrix (DSM) </span>
- <span class="definition"> used to  visualize file relations </span>
- <span class="definition">  a square matrix, in which rows and columns are labeled with file names in the same order </span>
- <span class="definition"> an annotation in the cell in row x, column y, c(rx, cy), indicates that there is a dependency relation between file x and file y </span>

<span class="term"> Design Rule Space </span>
- <span class="definition"> model the fact that the architecture of a software system can and should be represented as a set of overlapping design spaces, each reflecting an unique aspect of the architecture </span>
- <span class="definition"> each feature implemented, or each pattern applied can be modeled as an individual design space. </span>
- <span class="definition"> each DRSpace contains one or more “leading files”, typically design rules that all the other files within the design space depend on directly or indirectly. In other words, files within a DRSpace are architecturally connected. </span>
- <span class="definition"> if an inheritance hierarchy is implemented, all files involved in the inheritance tree could form a DRSpace led by the parent class </span>
- <span class="definition">  is a subset of files connected by one or more relations, such as inheritance, call, etc. </span>
- <span class="definition"> for any non-trivial project, there are numerous DRSpaces </span>
- <span class="definition"> majority of error-prone files can be captured by just a few DRSpaces, suggesting that most error-prone files in a project are architecturally connected</span>
- <span class="definition"> named these DRSpace <span class="term"> Architecture Roots </span></span>

# 3. ARCHITECTURE ANTI-PATTERNS
### A well-modularized system should have the following features: 
- <span class="definition"> design rules have to be stable: neither error-prone nor change-prone. </span>
- <span class="definition"> if two modules are truly independent, then they should only depend on design rules, but not on each other. </span>
- <span class="definition"> independent modules should be able to be changed, or even replaced, without influencing each other, as long as the design rules themselves remain unchanged. </span>

<span class="important"><span class="exclamation">!</span> The importance of design rules, that is, abstractions, are also reflected in the Liskov substitution, Interface segregation, and Dependency inversion principles. T </span>

<span class="important"><span class="exclamation">!</span> Summarized six types of recurring problems into a suite of Architecture Anti-Patterns, each violating one or more design principles and/or design rule theory. </span>

<img src="img/Definitions.png" alt="Effective testing">

## Architecture anti-patterns
<span class="important"><span class="exclamation">!</span> For each architecture anti-pattern, we now introduce its rationale, description, and formalization </span> 

### Unstable Interface (UIF)
- <span class="term"> Rationale </span><span class="definition"> - important and influential abstractions (design rules) should be stable. Otherwise their bugs and changes can be propagated to multiple files. </span> <span class="important"><span class="exclamation">!</span> unstable or poorly-designed abstractions are often related to high-maintenance </span> 
- <span class="term"> Description </span><span class="definition"> If a highly influential file (files with a large number of dependents) is changed frequently with other files as shown in the revision history, then we call it an Unstable Interface </span>
- <span class="term"> Formalization </span>
    - <span class="term"> StructImpact<sub>thr</sub> </span><span class="definition"> threshold of the structural impact scope of a file, f<sub>i</sub> . If the number of its dependents is larger than the threshold, we consider f<sub>i</sub> to be a candidate unstable interface. </span>
    - <span class="term"> HistoryImpact<sub>thr</sub> </span><span class="definition"> threshold of the number of co-changed dependents of f<sub>i</sub>. This requires that f<sub>i</sub> not only has more than StructImpact<sub>thr</sub> dependents, but also has more than HistoryImpact<sub>thr</sub> of these dependents changed together frequently with it </span>
    - <span class="term"> cochange<sub>thr</sub> </span><span class="definition"> threshold of co-change frequency. If two files are committed together more times than this threshold, we consider these two files to have changed together “frequently” and that they are evolutionarily coupled. </span>

<span class="important"><span class="exclamation">!</span> For a file f<sub>i</sub>, if it has more than StructImpact<sub>thr</sub> dependents, and more than  HistoryImpact<sub>thr</sub> of these dependents changed together with it more than cochange<sub>thr</sub> times, we consider f<sub>i</sub> to be an Unstable Interface. </span>   

<img src="img/UIF.png" alt="Effective testing">

### Modularity Violation Group (MVG).
- <span class="term"> Rationale </span><span class="definition"> independent modules can be changed or even replaced without influencing each other. Modularity Violation - describes two structurally independent modules that change together frequently, meaning that they are not truly independent</span>
- <span class="term"> Description </span><span class="definition"> In a Modularity Violation Group, there exists a core file, f<sub>core</sub>, which all other files are not structurally related to, but have frequently changed together with. To identify a Modularity Violation Group (MVG), our tool first generates all filesets by considering each file in a project as a core file, then greedily searches a fileset that covers most violated file pairs as a MVG, until the union of all the MVGs covers all violated file pairs in a project. </span>
- <span class="term"> Formalization </span> just a formula explained.<span class="definition"> </span>
- <span class="term"> cochange<sub>thr</sub> </span><span class="definition"> </span>

<img src="img/MVG.png" alt="Effective testing">

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> -->

### Unhealthy Inheritance Hierarchy (UIH)
- <span class="term"> Rationale </span><span class="definition"> object-oriented design principles are violated in the implementation of an inheritance hierarchy. The two most frequent problems are: 
    - a parent class depends on one of its children;
    - a client class of the hierarchy depends on both the base class and its children. 
    Both cases violate:
        - Liskov Substitution principle, since the parent class can no longer be a placeholder substitutable by any of its children. 
        - The Design Rule Theory because the parent class cannot be a decoupling design rule. 
        - The Dependency Inversion Principle since a client should depend on abstractions, not on concretions.</span>
- <span class="term"> Description </span><span class="definition"> We consider an inheritance hierarchy to be problematic if it falls into one of the following two cases:
    - Given an inheritance hierarchy containing one parent file, f<sub>parent</sub>, and one or more children, F<sub>child</sub>, there exists a child file f<sub>i</sub> satisfying depend(f<sub>parent</sub>, f<sub>i</sub>)
    - Given an inheritance hierarchy containing one parent file, f<sub>parent</sub>, and one or more children, F<sub>child</sub>, there exists a client f<sub>j</sub> of the hierarchy, that depends on both the parent and one or more of its children.
</span>
- <span class="term"> Formalization </span><span class="definition"> </span>

<img src="img/UIH.png" alt="Effective testing">

### Crossing (CRS).
- <span class="term"> Rationale </span><span class="definition"> </span>
- <span class="term"> Description </span><span class="definition"> </span>
- <span class="term"> Formalization </span><span class="definition"> </span>
<img src="img/Crossing.png" alt="Effective testing">

### Clique (CLQ).
- <span class="term"> Rationale </span><span class="definition"> </span>
- <span class="term"> Description </span><span class="definition"> </span>
- <span class="term"> Formalization </span><span class="definition"> </span>
<img src="img/Clique.png" alt="Effective testing">

### Package Cycle (PKC).
- <span class="term"> Rationale </span><span class="definition"> </span>
- <span class="term"> Description </span><span class="definition"> </span>
- <span class="term"> Formalization </span><span class="definition"> </span>
<img src="img/PKC.png" alt="Effective testing">