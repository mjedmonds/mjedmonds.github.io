// Course sites are legacy static pages (see src/integrations/legacy.ts).
export interface Course {
  title: string;
  href: string;
  terms?: string;
  summary: string;
}

export const courses: Course[] = [
  {
    title: 'SMC CS 80 · Internet Programming',
    href: '/CS80/CS80.html',
    summary:
      'An introduction to Internet technologies. Survey course covering HTML5, CSS, JavaScript, jQuery, DOM, XML, JSON, Ajax, web servers, SQL, and PHP. Project-oriented course.',
  },
  {
    title: 'SMC CS 50 · Introduction to C Programming',
    href: '/CS50/CS50.html',
    summary:
      'An introduction to C programming. Covers C fundamentals: control flow, loops, functions, pointers, arrays, strings, recursion, command-line arguments, structures, and enumerations.',
  },
  {
    title: 'SMC CS 52 · Introduction to C++ Programming',
    href: '/CS52/CS52.html',
    summary:
      'An introduction to C++ programming. Covers C++ fundamentals: control flow, loops, functions, classes, pointers, arrays, strings, recursion, command-line arguments, structures, and enumerations.',
  },
  {
    title: 'UCLA CS 31 · Introduction to Computer Science I',
    href: '/CS31/CS31.html',
    terms: 'Fall 2015, Winter 2016',
    summary:
      'Introduction to computer science via theory, applications, and programming. Basic data types, operators and control structures. Input/output. Procedural and data abstraction. Introduction to object-oriented software development. Functions, recursion. Arrays, strings, pointers. Abstract data types, object-oriented programming.',
  },
  {
    title: 'UCLA CS 32 · Introduction to Computer Science II',
    href: '/CS32/CS32.html',
    terms: 'Spring 2016',
    summary:
      'Object-oriented software development. Abstract data type definition and use. Overloading, inheritance, polymorphism. Object-oriented view of data structures: stacks, queues, lists. Algorithm analysis. Trees, graphs, and associated algorithms. Searching and sorting.',
  },
];
