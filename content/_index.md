---
title: ""
summary: ""
date: "2026-01-05"
type: "landing"
sections:
  - block: "dev-hero"
    content:
      username: "me"
      greeting: ""
      text: "Co-Director and Game Developer at Mad Moon Studios"
      show_status: false
      show_scroll_indicator: false
      cta_buttons:
        - text: "Check out my Work!"
          url: "#projects"
          icon: "arrow-down"
      links:
        - icon: "brands/linkedin"
          url: "https://www.linkedin.com/in/joshmccamley/"
        - icon: "brands/github"
          url: "https://github.com/your-username"
        - icon: "brands/itch-io"
          url: "https://your-username.itch.io/"
      bio: "Co-Director and Game Developer at Mad Moon Studios"
    design:
      style: "centered"
      avatar_shape: "circle"
      animations: true
      spacing:
        padding:
          - "8rem"
          - "1rem"
          - "8rem"
          - "1rem"
    ce: "section-hero"
    id: "hero"
    As: "section-8ede42dd"
  - block: "portfolio"
    content:
      title: "My Projects"
      subtitle: ""
      count: 0
      filters:
        folders:
          - "projects"
      buttons:
        - name: "All"
          tag: "*"
        - name: "Games"
          tag: "Games"
        - name: "Tools"
          tag: "Tools"
      default_button_index: 0
    design:
      view: "showcase"
      columns: 3
      background:
        color:
          light: "#ffffff"
          dark: "#0d0d12"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
      animations: false
    ce: "section-projects"
    id: "projects"
    As: "section-1995ef5c"
  - block: "tech-stack"
    content:
      title: "Tech"
      subtitle: "Things I like to use"
      categories:
        - name: "Languages"
          items:
            - name: "C++"
              icon: "devicon/cplusplus"
        - name: "Software"
          items:
            - name: "UE5"
              icon: "brands/unreal"
            - name: "Blender"
              icon: "devicon/blender"
            - name: "Obsidian"
              icon: "brands/obsidian"
        - name: "Source"
          items:
            - name: "Github"
              icon: "devicon/github"
            - name: "Perforce"
              icon: "assets/media/icons/perforce.svg"
    design:
      style: "grid"
      show_levels: false
      background:
        color:
          light: "#f5f5f5"
          dark: "#08080c"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-skills"
    id: "skills"
    As: "section-03113be1"
  - block: "resume-experience"
    content:
      title: "Experience"
      date_format: "Jan 2006"
      items:
        - title: "Senior Software Engineer"
          company: "Tech Corp"
          company_url: ""
          company_logo: ""
          location: "San Francisco, CA"
          date_start: "2023-01-01"
          date_end: ""
          description: |-
            * Lead development of microservices architecture serving 1M+ users
            * Improved API response time by 40% through optimization
            * Mentored team of 5 junior developers
            * Tech stack: React, Node.js, PostgreSQL, AWS
        - title: "Full-Stack Developer"
          company: "Startup Inc"
          company_url: ""
          company_logo: ""
          location: "Remote"
          date_start: "2021-06-01"
          date_end: "2022-12-31"
          description: |-
            * Built and deployed 3 production applications from scratch
            * Implemented CI/CD pipeline reducing deployment time by 60%
            * Collaborated with design team on UI/UX improvements
            * Tech stack: Next.js, Express, MongoDB, Docker
        - title: "Junior Developer"
          company: "Web Agency"
          company_url: ""
          company_logo: ""
          location: "New York, NY"
          date_start: "2020-01-01"
          date_end: "2021-05-31"
          description: |-
            * Developed client websites using modern web technologies
            * Maintained and updated legacy codebases
            * Participated in code reviews and agile ceremonies
            * Tech stack: React, WordPress, PHP, MySQL
    design:
      columns: "1"
      background:
        color:
          light: "#ffffff"
          dark: "#0d0d12"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-experience"
    id: "experience"
    As: "section-82dbc876"
  - block: "collection"
    content:
      title: "Recent Posts"
      subtitle: "Thoughts on web development, tech, and more"
      text: ""
      filters:
        folders:
          - "blog"
        exclude_featured: false
      count: 3
      order: "desc"
    design:
      view: "card"
      columns: 3
      background:
        color:
          light: "#f5f5f5"
          dark: "#08080c"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-blog"
    id: "blog"
    As: "section-8cb092e5"
  - block: "contact-info"
    content:
      title: "Get In Touch"
      subtitle: "Let's build something amazing together"
      text: |-
        I'm always interested in hearing about new projects and opportunities.
        Whether you're looking to hire, collaborate, or just want to say hi, feel free to reach out!
      email: "alex@example.com"
      autolink: true
    design:
      columns: "1"
      background:
        color:
          light: "#ffffff"
          dark: "#0d0d12"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-contact"
    id: "contact"
    As: "section-7a252383"
  - block: "markdown"
    content:
      title: ""
      text: |
        <style>
          /* 1. Full-bleed background image for the Hero Section */
          #hero {
            /* We added a dark linear-gradient overlay before the url() */
            background-image: linear-gradient(rgba(15, 23, 42, 0.3), rgba(15, 23, 42, 0.4)), url('/hero-bg.jpg') !important; 
            background-size: cover !important;
            background-position: center !important;
            background-attachment: fixed !important;
            position: relative;
            border-bottom: 1px solid rgba(255, 255, 255, 0.1);
          }

        /* 2. Turn ONLY the content container into a centered Glass Island */
          #hero > div:has(h1) {
            background-color: rgba(30, 41, 59, 0.75) !important;
            backdrop-filter: blur(12px);
            -webkit-backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.1) !important;
            border-radius: 2rem !important;
            padding: 3.5rem 2rem !important;
            max-width: 600px !important; 
            margin: 0 auto !important; 
            box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.5) !important; 
          }
          /* 4. Resize the Profile Picture AND its circular mask */
          #hero img {
            width: 200px !important; 
            height: 200px !important; 
            max-width: none !important;
            object-fit: cover !important; /* Ensures the image doesn't stretch weirdly */
          }

          /* Target the invisible wrapper container */
          #hero div:has(> img), 
          #hero a:has(> img),
          #hero span:has(> img) {
            width: 200px !important;
            height: 200px !important;
            max-width: 200px !important;
            border-radius: 50% !important; /* Enforces the perfect circle */
            overflow: hidden !important;   /* Clips anything outside the circle */
            margin: 0 auto !important;     /* Keeps the avatar perfectly centered */
          }
          /* Force the Unreal Engine logo to be pure white */
          [class*="unrealengine"], 
          img[src*="unrealengine"], 
          svg:has([id*="unrealengine"]) {
            color: white !important;
            fill: white !important;
            filter: brightness(0) invert(1) !important; /* Turns any color/black asset pure white */
          }
          /* --- FIX: Make the entire Project Card clickable --- */
          
          /* 1. Set the boundary for the clickable area without breaking native animations */
          #projects .group,
          #projects .card {
            position: relative !important;
          }

          /* 2. Stretch the title/image link to completely cover the card */
          #projects .group h2 a::after,
          #projects .group h3 a::after,
          #projects .group a:first-of-type::after {
            content: "";
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            z-index: 20; /* Ensures it sits firmly on top of the text and images */
          }
        </style>
    design:
      spacing:
        padding:
          - "0"
          - "0"
          - "0"
          - "0"
    ce: "section-43a65081"
    As: "section-0eee42b6"
---
