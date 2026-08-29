---
title: Perforce Live Feed on Nextcloud
date: 2026-02-06
summary: A custom Nextcloud app for easier debugging and diffing of Perforce files.
  <ul class="card-achievements">
    <li>Hooks into <span class="keyword-red">Perforce via CLI shell scripts</span>.</li>
    <li><span class="keyword-red">Local JSON Chaching</span> for better web performance.</li>
    <li><span class="keyword-red">Searchable Activity Feed</span>.</li>
    <li>Data-Oriented <span class="keyword-red">Solo Built</span> using Nextcloud's App framework and some custom CSS and Controllers.</li>

  </ul>
  <div class="card-status-container">
    <span class="status-tag status-proprietary">Proprietary</span>
    <span class="status-tag status-alpha">Alpha</span>

  </div>
# Optional: reference your webm file directly in front matter for JS targeting
preview_video: "Module Spin Sped Up.webm"
tags:
  - Tools
  - Web Dev
  - Perforce
  - Nextcloud
image:
  focal_point: "top"
  preview_only: true
---

<style>
  /* 1. Set the fixed, darkened background image for the whole page */
  body {
    background-image: linear-gradient(rgba(15, 23, 42, 0.55), rgba(15, 23, 42, 0.85)), url('featured.jpg') !important;
    background-size: cover !important;
    background-attachment: fixed !important;
    background-position: top !important;
  }

  /* 2. Wrap your content in a premium "glass" card */
  article {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border: 1px solid rgba(255, 255, 255, 0.1);
    border-radius: 1.5rem;
    padding: 3rem;
    margin-top: 3rem;
    margin-bottom: 3rem;
    width: 100% !important;
    max-width: 900px !important;
    margin-left: auto !important;
    margin-right: auto !important;
  }

  /* Prevent browser anchor jumps from overshooting */
  article h2, article h3 {
    scroll-margin-top: 120px !important;
  }

  /* 3. Table of Contents - Glass Card & Links */
  .hb-toc > div {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border-radius: 1rem;
    padding: 1.5rem !important;
    border-left: 4px solid #e05e5e !important; 
    height: fit-content !important; 
    margin-top: 3rem !important;
  }

  .hb-toc p {
    color: white !important;
    font-size: 1.1rem !important;
    margin-bottom: 1rem !important;
    font-weight: 600 !important;
    text-transform: none !important;
  }

  .hb-toc ul {
    list-style: none !important;
    padding-left: 0 !important;
    margin: 0 !important;
  }
  
  .hb-toc ul ul {
    padding-left: 1rem !important; 
  }

  .hb-toc a {
    color: #94a3b8 !important; 
    text-decoration: none !important;
    display: block !important;
    padding: 0.35rem 0.8rem !important;
    border-radius: 9999px !important; 
    transition: all 0.2s ease-in-out;
    margin-bottom: 0.25rem !important;
    font-size: 0.9rem !important;
    border: 1px solid transparent !important; 
  }

  .hb-toc a:hover {
    color: white !important;
    background-color: rgba(255, 255, 255, 0.05) !important;
  }

  .hb-toc a.red-pill-active {
    color: white !important;
    border: 1px solid #e05e5e !important; 
    background-color: transparent !important;
  }

  /* ========================================== */
  /* TONY'S HIGHLIGHTS & TAGS CSS               */
  /* ========================================== */

  .article-tags, 
  .pub-tags, 
  div:has(> a[href*="/tags/"]) {
    display: none !important;
  }

  .tony-blurb {
    border-left: 4px solid #e05e5e;
    padding-left: 1.5rem;
    margin: 1.5rem 0 2.5rem 0;
    font-size: 1.05rem !important;
    line-height: 1.6;
    color: #94a3b8;
    font-style: italic;
  }

  .tony-specs-container {
    display: flex;
    flex-direction: column;
    gap: 0.8rem;
    margin-bottom: 2.5rem;
  }

  .tony-spec-row {
    display: flex;
    align-items: center;
    gap: 1rem;
    color: white;
  }

  .tony-spec-row i {
    width: 24px;
    font-size: 1.25rem;
    text-align: center;
    color: #cbd5e1;
  }

  .tony-pill {
    padding: 0.25rem 0.8rem;
    border-radius: 0.35rem;
    font-size: 0.85rem;
    font-weight: 700;
    letter-spacing: 0.025em;
  }

  .tony-pill.blue {
    background-color: #0070f3;
    color: white;
  }

  .tony-pill.black {
    background-color: #000000;
    color: white;
    border: 1px solid rgba(255, 255, 255, 0.15);
  }

  .tony-highlights-card {
    background-color: rgba(30, 41, 59, 0.2);
    border: 2px solid rgba(224, 94, 94, 0.35);
    border-radius: 1rem;
    padding: 2rem;
    margin-bottom: 3rem;
  }

  .tony-highlights-card h3 {
    color: white !important;
    font-size: 1.35rem !important;
    font-weight: 700 !important;
    margin-top: 0 !important;
    margin-bottom: 1.25rem !important;
    display: flex;
    align-items: center;
    gap: 0.6rem;
  }

  .tony-highlights-card h3 i {
    color: #e05e5e;
  }

  .tony-highlights-card ul {
    list-style-type: disc !important;
    padding-left: 1.5rem !important;
    margin: 0 !important;
  }

  .tony-highlights-card li {
    color: #cbd5e1 !important;
    margin-bottom: 0.85rem !important;
    line-height: 1.6;
    font-size: 1rem;
  }

  .tony-highlights-card li:last-child {
    margin-bottom: 0 !important;
  }

  .keyword-red {
    color: #e05e5e;
    font-weight: 600;
  }

  /* ========================================== */
  /* GLASS IMAGE CAROUSEL CSS                   */
  /* ========================================== */
  .glass-carousel {
    display: flex;
    gap: 1rem;
    overflow-x: auto;
    padding-bottom: 1rem;
    margin-top: 2rem;
    margin-bottom: 2rem;
    scroll-snap-type: x mandatory;
    scrollbar-width: thin;
    scrollbar-color: #e05e5e rgba(255, 255, 255, 0.05);
  }

  .glass-carousel::-webkit-scrollbar {
    height: 8px;
  }
  .glass-carousel::-webkit-scrollbar-track {
    background: rgba(255, 255, 255, 0.05);
    border-radius: 4px;
  }
  .glass-carousel::-webkit-scrollbar-thumb {
    background: #e05e5e;
    border-radius: 4px;
  }

  .glass-carousel img {
    height: 300px; 
    width: auto;
    border-radius: 0.8rem;
    border: 1px solid rgba(255, 255, 255, 0.1);
    box-shadow: 0 4px 15px rgba(0,0,0,0.3);
    scroll-snap-align: start;
    flex-shrink: 0;
    object-fit: cover;
    background-color: rgba(0, 0, 0, 0.5); 
    cursor: pointer;
    transition: transform 0.2s ease, border-color 0.2s ease;
  }

  .glass-carousel img:hover {
    transform: scale(1.02);
    border-color: #e05e5e;
  }

/* ========================================== */
  /* GLOBAL GLASS LIGHTBOX OVERRIDE             */
  /* ========================================== */
  #lightbox-modal {
    position: fixed !important;
    z-index: 999999 !important;
    top: 0 !important;
    left: 0 !important;
    width: 100vw !important;
    height: 100vh !important;
    background-color: rgba(15, 23, 42, 0.88) !important;
    backdrop-filter: blur(12px) !important;
    -webkit-backdrop-filter: blur(12px) !important;
    display: flex !important;
    justify-content: center !important;
    align-items: center !important;
    opacity: 0;
    pointer-events: none;
    transition: opacity 0.2s ease-in-out;
  }

  #lightbox-modal.lightbox-visible {
    opacity: 1 !important;
    pointer-events: auto !important;
  }

  /* Targets both images and videos inside the modal */
  #lightbox-modal img,
  #lightbox-modal video {
    max-width: 85vw !important;
    max-height: 80vh !important;
    border-radius: 1rem !important;
    box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.8) !important;
    border: 1px solid rgba(255, 255, 255, 0.15) !important;
    object-fit: contain !important;
  }

  /* ========================================== */
  /* COLLAPSIBLE CODE BLOCKS CSS                */
  /* ========================================== */
  details.code-dropdown {
    background: rgba(30, 41, 59, 0.4);
    border: 1px solid rgba(255, 255, 255, 0.1);
    border-radius: 0.5rem;
    margin-top: 1rem;
    margin-bottom: 1.5rem;
    overflow: hidden;
  }

  details.code-dropdown summary {
    padding: 1rem;
    font-weight: 600;
    color: #e05e5e;
    cursor: pointer;
    user-select: none;
    outline: none;
    transition: background 0.2s ease;
  }

  details.code-dropdown summary:hover {
    background: rgba(255, 255, 255, 0.05);
  }

  details.code-dropdown .highlight {
    margin: 0 !important;
    border-radius: 0 0 0.5rem 0.5rem;
  }

  details.code-dropdown .highlight pre {
    background-color: rgba(10, 15, 24, 0.95) !important;
    padding: 1.25rem !important;
  }

  details.code-dropdown .highlight code {
    font-size: 0.8rem !important;
    line-height: 1.5 !important;
  }

  article p, 
  article li {
    font-size: 0.95rem !important;
    line-height: 1.6 !important;
  }

  /* ========================================== */
  /* MOBILE RESPONSIVENESS PATCH                */
  /* ========================================== */
  @media (max-width: 768px) {
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
</style>

<script>
  document.addEventListener('DOMContentLoaded', () => {
    // 1. Table of Contents Scroll Highlighting
    const observer = new IntersectionObserver((entries) => {
      entries.forEach(entry => {
        const id = entry.target.getAttribute('id');
        const link = document.querySelector(`.hb-toc a[href="#${id}"]`);
        
        if (entry.isIntersecting && link) {
          document.querySelectorAll('.hb-toc a').forEach(l => l.classList.remove('red-pill-active'));
          link.classList.add('red-pill-active');
        }
      });
    }, { rootMargin: '-20% 0px -70% 0px' });

    document.querySelectorAll('article h2, article h3').forEach(h => observer.observe(h));

    // 2. Auto-Injecting Lightbox (Handles both Images & Videos)
    let modal = document.getElementById('lightbox-modal');
    let modalImg = document.getElementById('lightbox-img');
    let modalVideo = document.getElementById('lightbox-video');

    if (!modal) {
      modal = document.createElement('div');
      modal.id = 'lightbox-modal';

      modalImg = document.createElement('img');
      modalImg.id = 'lightbox-img';

      modalVideo = document.createElement('video');
      modalVideo.id = 'lightbox-video';
      modalVideo.autoplay = true;
      modalVideo.loop = true;
      modalVideo.muted = true;
      modalVideo.playsInline = true;
      modalVideo.controls = true; // Gives native play/pause/fullscreen controls in the modal

      modal.appendChild(modalImg);
      modal.appendChild(modalVideo);
      document.body.appendChild(modal);
    }

    // Attach click events to all article IMAGES
    document.querySelectorAll('article img').forEach(img => {
      img.style.cursor = 'pointer';
      img.addEventListener('click', (e) => {
        e.preventDefault();
        e.stopPropagation();
        modalVideo.style.display = 'none';
        modalVideo.pause();
        modalImg.src = img.src;
        modalImg.style.display = 'block';
        modal.classList.add('lightbox-visible');
      });
    });

    // Attach click events to all article VIDEOS
    document.querySelectorAll('article video').forEach(video => {
      video.style.cursor = 'pointer';
      video.addEventListener('click', (e) => {
        e.preventDefault();
        e.stopPropagation();
        const src = video.currentSrc || video.querySelector('source')?.src;
        if (src) {
          modalImg.style.display = 'none';
          modalVideo.src = src;
          modalVideo.style.display = 'block';
          modalVideo.play();
          modal.classList.add('lightbox-visible');
        }
      });
    });

    // Close modal and reset video playback on click anywhere
    modal.addEventListener('click', () => {
      modal.classList.remove('lightbox-visible');
      if (modalVideo) {
        modalVideo.pause();
        modalVideo.src = '';
      }
    });
  });
</script>

<div class="tony-blurb">
  A Nextcloud app that provides a fully searchable, live feed of checked out files and pending changelists, minimising workflow overlap and accelerating file debugging and diffing, instantly becoming a daily tool the team relies upon.
</div>

<div class="tony-specs-container">
  <div class="tony-spec-row">
    <i class="fas fa-desktop"></i>
    <span class="tony-pill blue">Linux</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-code"></i>
    <span class="tony-pill blue">Web Dev</span>
    <span class="tony-pill blue">Perforce</span>
    <span class="tony-pill blue">Nextcloud</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">CSS</span>
    <span class="tony-pill black">Optimisation</span>
    <span class="tony-pill black">Tools</span>
  </div>
</div>

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <a data-fancybox="gallery" href="featured.jpg" data-caption="TrueNAS Apps Interface">
  <img src="featured.jpg" alt="ProcTex Plugin Interface" style="width: 100%; height: auto; display: block;" />
    </a>
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i>Extended Highlights</h3>
  <ul>
    <li>Built a custom Nextcloud Live App that hooks into <span class="keyword-red">Perforce via CLI shell scripts</span>, stripping away P4V's clunky interface for a clean web dashboard.</li>
    <li>Solved performance lag by adding a <span class="keyword-red">Local JSON Cache and custom PHP env wrappers</span> to handle heavy P4 queries seamlessly.</li>
    <li>Cleared team visibility bottlenecks with a <span class="keyword-red">Searchable Activity Feed</span>, turning raw CLI logs into live updates on who is editing what.</li>
    <li>Turned a brand new workflow into an essential <span class="keyword-red">Daily Routine</span>, helping everyone jump into work fully prepared with instant context.</li>
  </ul>
</div>

## Making Perforce a little more Accessible

While Perforce is an industry standard, its interface and visibility felt a little too complex for the team. They would frequently start their day unaware of exactly what others were working on or which files were currently locked, especially in the early days of getting everyone onboarded to Perforce.

To solve this, I developed a custom Nextcloud application that ties directly into our Perforce server. This integration provides a live feed of project activity right in the browser, completely removing the friction of traditional clients, and lets you see checked out files without opening the engine! 

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <video autoplay loop muted playsinline style="width: 100%; height: auto; display: block; margin: 0 !important;">
    <source src="PerforceLiveApp.webm" type="video/webm">
  </video>
</div>

## Live Tracking & Preparation

By exposing Perforce data through Nextcloud, the app instantly transformed how the team worked:

* **Live Activity Feed:** Team members can see exactly what files are checked out and view pending changelists in real time. This lets everyone feel more prepared starting their day, with full awareness of ongoing work.

* **Proper Search:** Fully searchable submissions and pending changelists allowed anyone to quickly find when specific revisions happened.

* **Better Context:** Having a highly searchable, web based history provides immediate context when diffing files or debugging tricky issues.