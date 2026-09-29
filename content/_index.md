---
title: ""
summary: ""
date: "2026-01-04"
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
        - text: "Download CV"
          url: "uploads/Josh McCamley Technical Game Designer.pdf"
          icon: "hero/document-arrow-down"
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
          dark: "#12151d"
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
            - name: "Blueprints/Visual Scripting"
              icon: "brands/unrealengine"
            - name: "C++"
              icon: "devicon/cplusplus"
        - name: "Software"
          items:
            - name: "UE5"
              icon: "brands/unrealengine"
            - name: "Blender"
              icon: "devicon/blender"
            - name: "Obsidian"
              icon: "brands/obsidian"
            - name: "FMOD"
              icon: "brands/fmod"
            - name: "Visual Studio"
              icon: "brands/visualstudio"
            - name: "Jet Brains Rider"
              icon: "brands/rider"
        - name: "Source"
          items:
            - name: "Github"
              icon: "devicon/github"
            - name: "Perforce"
              icon: "brands/perforce"
    design:
      style: "grid"
      show_levels: false
      background:
        color:
          light: "#f5f5f5"
          dark: "#12151d"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-skills"
    id: "skills"
    As: "section-03113be1"
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
          dark: "#12151d"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-blog"
    id: "blog"
    As: "section-8cb092e5"
  - block: "markdown"
    content:
      title: ""
      text: |
        <div id="steam-recent-section">
          <div class="steam-section-header">
            <i class="fab fa-steam"></i>
            <h2>Recently Played</h2>
          </div>
          {{< steam_recent >}}
        </div>

        <style>
          /* 1. Full-bleed background image for the Hero Section */
          #hero {
            background-image: linear-gradient(rgba(15, 23, 42, 0.3), rgba(15, 23, 42, 0.4)), url('hero-bg.jpg') !important; 
            background-size: cover !important;
            background-position: center !important;
            background-attachment: fixed !important;
            position: relative;
            border-bottom: 1px solid rgba(255, 255, 255, 0.1);
          }

          /* Centered Glass Island for Hero Intro */
          #hero > div:has(h1) {
            background-color: rgba(30, 41, 59, 0.75) !important;
            backdrop-filter: blur(12px);
            -webkit-backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.1) !important;
            border-radius: 2rem !important;
            padding: 2.5rem 2rem !important;
            max-width: 720px !important; 
            margin: 0 auto !important; 
            box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.5) !important; 
          }

          #hero h1 {
            font-size: 3.8rem !important;
            line-height: 1.2 !important;
            margin-top: 1rem !important;
            margin-bottom: 0.5rem !important;
          }

          /* Profile Picture Avatar Styling */
          #hero img:not(#steam-recent-section img) {
            width: 200px !important; 
            height: 200px !important; 
            max-width: none !important;
            object-fit: cover !important;
          }

          #hero div:has(> img):not(#steam-recent-section *), 
          #hero a:has(> img):not(#steam-recent-section *),
          #hero span:has(> img):not(#steam-recent-section *) {
            width: 200px !important;
            height: 200px !important;
            max-width: 200px !important;
            border-radius: 50% !important;
            overflow: hidden !important;
            margin: 0 auto !important;
          }

          /* 2. Standalone Steam Section Above Contact */
          #steam-recent-section {
            background-color: rgba(30, 41, 59, 0.6) !important;
            backdrop-filter: blur(12px);
            -webkit-backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.1) !important;
            border-radius: 1.5rem !important;
            padding: 2.5rem !important;
            max-width: 900px !important;
            margin: 0 auto !important;
            box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.5) !important;
          }

          .steam-section-header {
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 0.75rem;
            color: #ffffff;
            margin-bottom: 1.5rem;
          }

          .steam-section-header i {
            color: #e05e5e;
            font-size: 1.8rem;
          }

          .steam-section-header h2 {
            font-size: 1.75rem !important;
            font-weight: 700 !important;
            color: #ffffff !important;
            margin: 0 !important;
          }

          /* STEAM GAME IMAGES - PERFECT 1:1 SQUARE FIT */
          #steam-recent-section .steam-img-container {
            width: 100% !important;
            aspect-ratio: 1 / 1 !important;
            height: auto !important;
            border-radius: 0.5rem 0.5rem 0 0 !important;
            overflow: hidden !important;
            background-color: rgba(15, 23, 42, 0.6) !important;
          }

          #steam-recent-section .steam-game-card img {
            width: 100% !important;
            height: 100% !important;
            max-width: 100% !important;
            object-fit: cover !important;
            border-radius: 0 !important;
            display: block !important;
            margin: 0 !important;
          }

          /* Unreal Engine Logo Brightness */
          [class*="unrealengine"], 
          img[src*="unrealengine"], 
          svg:has([id*="unrealengine"]) {
            color: white !important;
            fill: white !important;
            filter: brightness(0) invert(1) !important;
          }

          /* Project Cards Interactive State */
          #projects .group,
          #projects .card {
            position: relative !important;
            transition: transform 0.3s ease, box-shadow 0.3s ease, border-color 0.3s ease !important;
          }

          #projects .group h2 a::after,
          #projects .group h3 a::after,
          #projects .group a:first-of-type::after {
            content: "";
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            z-index: 20;
          }

          /* MOBILE RESPONSIVENESS PATCH */
          @media (max-width: 768px) {
            #steam-recent-section {
              padding: 1.5rem 1rem !important;
            }

            article {
              padding: 1rem 0.5rem !important;
              margin-top: 0.5rem !important;
              margin-bottom: 0.5rem !important;
              border-radius: 0.75rem !important;
            }

            .tony-blurb {
              padding-left: 0.75rem !important;
              margin-bottom: 1.25rem !important;
              font-size: 0.95rem !important;
            }
            
            article h1 { font-size: 1.7rem !important; }
            article h2 { font-size: 1.3rem !important; }
            article h3 { font-size: 1.15rem !important; }

            .clean-carousel a {
              flex: 0 0 95% !important; 
            }
            .clean-carousel img {
              height: 220px !important;  
            }
          }

          /* Achievements & Status Tags */
          .card-achievements {
            list-style-type: disc !important;
            padding-left: 1.2rem !important;
            margin-top: 0.75rem !important;
            margin-bottom: 0.75rem !important;
            font-size: 0.85rem !important;
            color: #94a3b8 !important;
          }
          .card-achievements li {
            margin-bottom: 0.25rem !important;
            line-height: 1.35 !important;
          }

          .card-status-container {
            margin-top: 1rem;
            margin-bottom: 0.5rem;
          }
          .status-tag {
            display: inline-block;
            padding: 0.35rem 0.85rem;
            font-size: 0.75rem;
            font-weight: 800;
            text-transform: uppercase;
            letter-spacing: 0.05em;
            border-radius: 0.5rem;
          }
          .status-in-dev     { background: rgba(224, 94, 94, 0.15); border: 1.5px solid #e05e5e; color: #f87171; }
          .status-vertical-slice     { background: rgba(224, 142, 94, 0.15); border: 1.5px solid #e0835e; color: #f8a371; }
          .status-prototype  { background: rgba(245, 158, 11, 0.15); border: 1.5px solid #f59e0b; color: #fbbf24; }
          .status-jam        { background: rgba(59, 130, 246, 0.15);  border: 1.5px solid #3b82f6; color: #60a5fa; }
          .status-released   { background: rgba(16, 185, 129, 0.15); border: 1.5px solid #10b981; color: #34d399; }
          .status-proprietary { background: rgba(139, 92, 246, 0.15); border: 1.5px solid #8b5cf6; color: #a78bfa; }
          .status-alpha       { background: rgba(92, 246, 195, 0.15); border: 1.5px solid #5cf6c8; color: #8bfacf; }

          /* Video Previews */
          #projects .featured-image-wrapper,
          #projects article div:has(> img),
          #projects .group a:has(> img) {
            position: relative !important;
            overflow: hidden !important;
          }

          .card-video-preview {
            position: absolute !important;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            object-fit: cover;
            opacity: 0;
            transition: opacity 0.3s ease-in-out;
            pointer-events: none;
            z-index: 10;
          }

          .keyword-red {
            color: #e0ac5e;
            font-weight: 600;
          }

          #projects article:hover,
          #projects .group:hover,
          #projects article.is-hovered,
          #projects .group.is-hovered {
            transform: translateY(-6px) scale(1.015) !important;
            box-shadow: 0 20px 40px -10px rgba(0, 0, 0, 0.6), 0 0 15px rgba(224, 94, 94, 0.25) !important;
            border-color: rgba(224, 94, 94, 0.6) !important;
          }

          #projects article:hover .card-video-preview,
          #projects .group:hover .card-video-preview,
          #projects article.is-hovered .card-video-preview,
          #projects .group.is-hovered .card-video-preview {
            opacity: 1 !important;
          }
        </style>

        <script>
          document.addEventListener('DOMContentLoaded', () => {
            // Project Video Hover & Scroll Observer
            const projectVideos = {
              'sol-construct': 'Module Spin Sped Up.webm',
              'perforce-live-app': 'PerforceLiveApp.webm',
              'self-hosted-dev-infrastructure': 'FBXViewerExample.webm',
              'sol-drift': 'SOL DRIFT Preview.webm',
              'shoot-to-die': 'ShootToDieReload.webm'
            };

            const isMobile = window.innerWidth <= 768 || 'ontouchstart' in window;

            const mobileCardObserver = new IntersectionObserver((entries) => {
              entries.forEach(entry => {
                const card = entry.target;
                const video = card.querySelector('.card-video-preview');

                if (entry.isIntersecting) {
                  card.classList.add('is-hovered');
                  if (video) video.play().catch(() => {});
                } else {
                  card.classList.remove('is-hovered');
                  if (video) {
                    video.pause();
                    video.currentTime = 0;
                  }
                }
              });
            }, {
              threshold: 0.60
            });

            document.querySelectorAll('#projects article, #projects .group').forEach(card => {
              const link = card.querySelector('a[href*="/projects/"]');
              if (!link) return;

              const href = link.getAttribute('href') || '';
              const key = Object.keys(projectVideos).find(k => href.toLowerCase().includes(k.toLowerCase()));
              if (!key) return;

              const imgWrapper = card.querySelector('div:has(> img)') || card.querySelector('a:has(> img)');
              if (!imgWrapper) return;

              const videoFilename = projectVideos[key];
              const videoSrc = href.replace(/\/$/, '') + '/' + encodeURI(videoFilename);

              const video = document.createElement('video');
              video.className = 'card-video-preview';
              video.src = videoSrc;
              video.loop = true;
              video.muted = true;
              video.playsInline = true;
              video.preload = 'metadata';
              imgWrapper.appendChild(video);

              card.addEventListener('mouseenter', () => {
                if (!isMobile) video.play().catch(() => {});
              });
              card.addEventListener('mouseleave', () => {
                if (!isMobile) {
                  video.pause();
                  video.currentTime = 0;
                }
              });

              if (isMobile) {
                mobileCardObserver.observe(card);
              }
            });
          });
        </script>
    design:
      columns: "1"
      background:
        color:
          light: "#ffffff"
          dark: "#12151d"
      spacing:
        padding:
          - "4rem"
          - "0"
          - "4rem"
          - "0"
    ce: "section-43a65081"
    As: "section-0eee42b6"
  - block: "contact-info"
    content:
      title: "Get In Touch"
      subtitle: "Let's chat!"
      text: |-
       Whether you're looking to fill a technical design role or you just want to talk engine architecture and game feel over a virtual coffee, my inbox is open. Hit me up on LinkedIn, or drop a direct email. Always down to chat!
      email: "joshmccamley@gmail.com"
      autolink: true
    design:
      columns: "1"
      background:
        color:
          light: "#ffffff"
          dark: "#12151d"
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