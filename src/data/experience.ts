// Experience page entries, newest first. `org` and bullets may contain inline HTML.
export interface Role {
  title: string;
  org: string;
  dates: string;
  location?: string;
  bullets?: string[];
}

export const work: Role[] = [
  {
    title: 'Staff Applied Scientist',
    org: '<a href="https://www.gm.com">General Motors</a>',
    dates: 'January 2026 – present',
    location: 'Remote',
  },
  {
    title: 'Senior Applied Scientist II',
    org: '<a href="https://getcruise.com">Cruise</a>',
    dates: 'October 2021 – December 2025',
    location: 'San Francisco, CA',
    bullets: [
      'Worked at the intersection of machine learning and planning on the Behavior Planning team; joined as a Senior Software Engineer working on maneuver planning.',
      'Used imitation learning, PyTorch, and ROS to deploy safer and more capable ML models to cars driving on the road.',
    ],
  },
  {
    title: 'Director and President',
    org: 'Center for AI and Robot Autonomy (CARA)',
    dates: 'March 2021 – May 2025',
    bullets: ['Defined updated mission and vision statements, sought alternative funding, and maintained 501(c)(3) status.'],
  },
  {
    title: 'Adjunct Professor',
    org: 'Santa Monica College',
    dates: 'June 2016 – September 2021',
    bullets: [
      'Taught one or two 45-student classes per quarter: led lectures, held office hours, and created course materials.',
      'Instructed 25 courses: Internet Programming (HTML, CSS, JavaScript, MySQL, and PHP), Intro to C, and Intro to C++. See <a href="/teaching/">teaching</a>.',
    ],
  },
  {
    title: 'Robotics Research Engineer Intern',
    org: 'Center for AI and Robot Autonomy (CARA)',
    dates: 'June 2018 – March 2020',
    bullets: ['Worked on a representation learning project coupling vision and language (see <a href="/research/language/">research</a>).'],
  },
  {
    title: 'Teaching Assistant',
    org: 'Computer Science Department, UCLA',
    dates: 'September 2015 – June 2016',
    bullets: ['Introduction to C and Introduction to C++: led discussion sections (~50 students) and held office hours.'],
  },
  {
    title: 'Teaching Assistant',
    org: 'Electrical &amp; Computer Engineering Department, University of Dayton',
    dates: 'January 2015 – May 2015',
    bullets: ['Electronic Devices Lab: aided in lab sessions (~40 students).'],
  },
  {
    title: 'Software Engineering Intern',
    org: 'Garmin International',
    dates: 'May 2013 – August 2013',
    bullets: [
      'Automated the testing process for small-craft airplane ACARS systems that send timed status messages to ground stations.',
      'Reduced testing time by 40% and saved hundreds of vendor certification testing hours by optimizing simulation timing protocols while adhering to FAA safety standards.',
    ],
  },
  {
    title: 'Enrichment Workshop Tutor',
    org: 'School of Engineering, University of Dayton',
    dates: 'September 2012 – May 2015',
    bullets: ['Tutored first-year engineering students in calculus, chemistry, and physics; led a team of 8 tutors overseeing 40 students.'],
  },
  {
    title: 'Summer School Teacher',
    org: 'Cristo Rey Kansas City',
    dates: 'May 2011 – August 2012',
    bullets: ['Taught four junior and senior classes at a prep school focused on college placement for underrepresented groups.'],
  },
];

export const education: Role[] = [
  {
    title: 'PhD in Computer Science, Artificial Intelligence concentration',
    org: 'University of California, Los Angeles',
    dates: 'September 2021',
    bullets: [
      'Dissertation: <a href="/papers/mjedmonds___PhD_Dissertation.pdf"><em>Learning How and Why: Causal Learning and Explanation from Physical, Interactive, and Communicative Environments</em></a>',
    ],
  },
  {
    title: 'M.S. in Computer Science',
    org: 'University of California, Los Angeles',
    dates: 'June 2017',
    bullets: ['Thesis: <em>Learning Complex Functional Manipulations by Human Demonstration and Fluent Discovery</em>'],
  },
  {
    title: 'B.S. in Computer Engineering, Magna Cum Laude',
    org: 'University of Dayton',
    dates: 'May 2015',
    bullets: ['Thesis: <em>High-Performance Declarative Memory through MapReduce</em>'],
  },
];
