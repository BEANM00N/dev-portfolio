---
title: ""
summary: ""
date: "2026-01-05"
type: "landing"
sections:
  - block: "dev-hero"
    content:
      username: "me"
      greeting: "Hi, I'm"
      show_status: false
      show_scroll_indicator: false
      typewriter:
        enable: false
        prefix: "I build"
        strings:
          - "full-stack web apps"
          - "scalable APIs"
          - "beautiful UIs"
          - "open source tools"
        type_speed: 70
        delete_speed: 40
        pause_time: 2500
      cta_buttons:
        - text: "Check out my Work!"
          url: "#projects"
          icon: "arrow-down"
      links:
        - icon: "brands/LI-In-Bug"
          url: "https://www.linkedin.com/in/joshmccamley/?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3B4uuo3CidQWuXa%2B3A%2Fk1VXw%3D%3D"
          label: ""
    design:
      style: "centered"
      avatar_shape: "circle"
      animations: true
      background:
        color:
          light: "#fafafa"
          dark: "#0a0a0f"
      spacing:
        padding:
          - "6rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-hero"
    id: "hero"
    As: "section-8ede42dd"
  - block: "portfolio"
    content:
      title: "Featured Projects"
      subtitle: "A selection of my recent work"
      count: 0
      filters:
        folders:
          - "projects"
      buttons:
        - name: "All"
          tag: "*"
        - name: "Full-Stack"
          tag: "Full-Stack"
        - name: "Frontend"
          tag: "Frontend"
        - name: "Backend"
          tag: "Backend"
      default_button_index: 0
    design:
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
    ce: "section-projects"
    id: "projects"
    As: "section-1995ef5c"
  - block: "tech-stack"
    content:
      title: "Tech Stack"
      subtitle: "Technologies I use to build things"
      categories:
        - name: "Languages"
          items:
            - name: "TypeScript"
              icon: "devicon/typescript"
            - name: "JavaScript"
              icon: "devicon/javascript"
            - name: "Python"
              icon: "devicon/python"
            - name: "Go"
              icon: "devicon/go"
        - name: "Frontend"
          items:
            - name: "React"
              icon: "devicon/react"
            - name: "Next.js"
              icon: "devicon/nextjs"
            - name: "Tailwind CSS"
              icon: "devicon/tailwindcss"
            - name: "Alpine.js"
              icon: "devicon/alpinejs"
        - name: "Backend"
          items:
            - name: "Node.js"
              icon: "devicon/nodejs"
            - name: "Express"
              icon: "devicon/express"
            - name: "PostgreSQL"
              icon: "devicon/postgresql"
            - name: "Redis"
              icon: "devicon/redis"
        - name: "DevOps"
          items:
            - name: "Docker"
              icon: "devicon/docker"
            - name: "AWS"
              icon: "devicon/amazonwebservices"
            - name: "GitHub Actions"
              icon: "brands/github"
            - name: "Vercel"
              icon: "devicon/vercel"
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
---
