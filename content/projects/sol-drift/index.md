---
title: SOL DRIFT
date: 2025-08-08
summary: Judge Dredd in a Jet. A Roguelite Jet fueled Shooter.
  <ul class="card-achievements">
    <li><span class="keyword-red">Player Movement:</span> Momentum, Drifting, Boosting, Dodging.</li>
    <li><span class="keyword-red">Enemy Logic:</span> Flight Pathing, Behaviour Trees, Attacks, Defenses.</li>
    <li><span class="keyword-red">All 3D Modelling and Texturing</span>.</li>
    <li>In-Game and Website <span class="keyword-red">Live Online Leaderboard.</span></li>

  </ul>
  <div class="card-status-container">
    <span class="status-tag status-vertical-slice">Vertical Slice</span>
  </div>
preview_video: "SOL DRIFT Preview.webm"
tags:
  - Games
  - Unreal Engine
  - Blueprints
  - Tech Art
  - C++
  - AI
image:
  focal_point: "top"
  preview_only: true
draft: false
---

<style>
  /* 1. Set the fixed, darkened background image for the whole page */
  body {
    background-image: linear-gradient(rgba(15, 23, 42, 0.55), rgba(15, 23, 42, 0.85)), url('featured.webp') !important;
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
  A Flight Shooter where perpetual, aggressive movement is your primary weapon and defense. Success depends on chaining an arsenal of movement abilities to evade death and create openings for attack.
</div>

<div class="tony-specs-container">
  <div class="tony-spec-row">
    <i class="fas fa-desktop"></i>
    <span class="tony-pill blue">Windows</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-code"></i>
    <span class="tony-pill blue">Blueprints</span>
    <span class="tony-pill blue">Mass Entity ECS</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">Unreal Engine 5</span>
    <span class="tony-pill black">AI & Pathfinding</span>
    <span class="tony-pill black">Tech Art</span>
  </div>
</div>

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <video autoplay loop muted playsinline style="width: 100%; height: auto; display: block; margin: 0 !important;">
    <source src="SOL DRIFT Preview 720p.webm" type="video/webm">
  </video>
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i>Extended Contributions</h3>
  <ul>
    <li><span class="keyword-red">Radial Upgrade Menu</span>, procedurally updated based on amount of rewards. .</li>
    <li><span class="keyword-red">Full Player Movement integration,</span> creating "Faked" momentum for customisable game feel.</li>
    <li><span class="keyword-red">Full Enemy Implementation</span>; Curve based flight paths, Behaviour Trees, Weaponry, Defenses (Chaff, Smoke, etc.).</li>
    <li>Every single <span class="keyword-red">3D Asset and associated Textures</span> and most animations.</li>
    <li>"Gyroscopic" Camera movement using <span class="keyword-red">Mouse Position and Curve based Sensitivity</span>.</li>
    <li><span class="keyword-red">Online Leaderboard Test:</span> Http Post/Get for sending and receiving data, hosted on a website using Google Firebase as backend for Testing.</li>
  </ul>
</div>

## Radial Menu

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <video autoplay loop muted playsinline style="width: 100%; height: auto; display: block; margin: 0 !important;">
    <source src="SOL DRIFT Radial Menu.webm" type="video/webm">
  </video>
</div>

Materials and UMG working hand-in-hand to generate a set of upgrades in a radial wheel, expandable to as many slices as you'd like or to whatever size text you're capable of reading! Fun solution to a problem that didn't quite have a determined direction, hence the procedural nature of it. It was also the first time I tried messing with generating SDF shapes in Materials, a trial that would come in handy in many future material endeavours. 

## Realtime Leaderboard

One of the coolest mixes of tech and game I got to experiment with. It never made it beyond the initial prototyping stages, but taught me heaps on how external data can be stored, streamed, updated and even influence gameplay!

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="FirebaseSetup.webp" class="zoomable" alt="Firebase Setup" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>

I needed a foundation to work with - one that could help with in-engine implementation and then be upgraded to a more secure and faster storage method - and with that in mind I decided to try Google Firebase's Realtime Databases. Before testing it in engine, I used simple services like Postman to test HTTPS Posting and Getting, a process that turned out to be a lot easier than I was expecting.

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="GameLeaderboard.webp" class="zoomable" alt="In-Game Leaderboard" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>

Next came Engine Implementation using some simple Maps and sorting based on score. Beyond just scoreboard data like Name and Score, we tested sending some other values, like ENTIRE save structs! That was a weird experiment, but bore some exceptionally useful fruit, allowing us to make changes on the fly during gameplay, unlocking ships, soft locks, and even adjust numbers on the fly for balancing. It ended up being the PERFECT playtesting tool, allowing live adjustments and comparisons across hundreds of players. We certaintly pushed this method to its limits, making our in game leaderboard take up to 2 minutes to load in game, just because of the sheer amount of data we were moving. Ended up being more of an online save system rather than solely a leaderboard if I'm honest.

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="WebsiteLeaderboard.webp" class="zoomable" alt="Website Leaderboard" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>

Since it was just a database stored somewhere somewhere on the internet, how much work could it be to render it somewhere that's accessible to anyone? Well a lot actually, especially if you don't have a lot of experience parsing data in html, nevermind stying it too! But in the end it was incredibly worth it. At in-person playtests we were able to set up a small screen in the middle of two rigs, incentivising players to engage in some social competition.