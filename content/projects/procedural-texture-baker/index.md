---
title: ProcTex Plugin
date: 2026-02-06
summary: Texture Pixelizer Plugin for Unreal Engine
  <ul class="card-achievements">
    <li><span class="keyword-red">C++ Editor tool</span> with Native UI Integration.</li>
    <li>Live 3D Previewer supporting <span class="keyword-red">all Mesh Types</span>.</li>
    <li>All Parameters <span class="keyword-red">exposed for Customisation</span>.</li>
  </ul>
  <div class="card-status-container">
    <span class="status-tag status-released">Released</span>
    <span class="status-tag status-alpha">Alpha</span>

  </div>
# Optional: reference your webm file directly in front matter for JS targeting
preview_video: "Module Spin Sped Up.webm"
tags:
  - Tools
  - Unreal Engine
  - Blueprints
  - C++
  - Tech Art
image:
  focal_point: "Top"
  preview_only: true
toc: true
---

<style>
  /* 1. Set the fixed, darkened background image for the whole page */
  body {
    background-image: linear-gradient(rgba(15, 23, 42, 0.55), rgba(15, 23, 42, 0.85)), url('ProcTex.webp') !important;
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

  /* --- GUARANTEED RED PILL ACTIVE STATE --- */
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
  /* CLEAN IMAGE CAROUSEL CSS                   */
  /* ========================================== */
  .clean-carousel {
    display: flex !important;
    gap: 1.5rem !important;
    overflow-x: auto !important;
    padding: 1rem 0 !important;
    scroll-snap-type: x mandatory !important;
    scrollbar-width: thin;
    scrollbar-color: #e05e5e rgba(255, 255, 255, 0.05);
  }

  .clean-carousel a,
  .clean-carousel > p,
  .clean-carousel > img {
    flex: 0 0 80% !important;
    max-width: 550px !important;
    flex-shrink: 0 !important;
    scroll-snap-align: center !important;
    text-decoration: none !important;
    display: flex !important;
    flex-direction: column !important;
    margin: 0 !important;
  }

  .clean-carousel img {
    width: 100% !important;
    height: 350px !important;
    object-fit: cover !important;
    border-radius: 1rem !important;
    border: 1px solid rgba(255, 255, 255, 0.1) !important;
    box-shadow: 0 10px 30px rgba(0,0,0,0.5) !important;
    transition: transform 0.2s ease, border-color 0.2s ease !important;
    margin: 0 !important;
    cursor: pointer;
  }

  .clean-carousel img:hover {
    transform: scale(1.02) !important;
    border-color: #e05e5e !important;
  }

  .clean-carousel-caption {
    text-align: center;
    font-size: 0.85rem;
    color: #94a3b8;
    font-style: italic;
    margin-top: 0.75rem;
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

    .clean-carousel a,
    .clean-carousel > p,
    .clean-carousel > img {
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
      modalVideo.controls = true;

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

<div style="margin-bottom: 2.5rem; max-width: 100%; border-radius: 0.5rem; overflow: hidden; display: inline-block; box-shadow: 0 4px 15px rgba(0,0,0,0.3);">
  <iframe frameborder="0" src="https://itch.io/embed/4676252?bg_color=242424&amp;fg_color=ffffff&amp;link_color=476ed3&amp;border_color=cc6b4a" width="552" height="167"><a href="https://mad-moon-studios.itch.io/proctex-plugin">ProcTex Plugin by Mad Moon Studios</a></iframe>
</div>

<div class="tony-blurb">
  Turn any texture into a retro asset directly inside Unreal Engine! ProcTex is a handy, lightweight Editor Utility Plugin for Unreal Engine 5.6 originally built as a pipeline tool for our game <b>SOL CONSTRUCT</b>. It allows you to down-res, posterize, and manipulate textures with a real-time 3D preview without ever leaving the Editor.
</div>

<div class="tony-specs-container">
  <div class="tony-spec-row">
    <i class="fas fa-desktop"></i>
    <span class="tony-pill blue">Windows</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-code"></i>
    <span class="tony-pill blue">C++</span>
    <span class="tony-pill blue">Blueprints</span>
    <span class="tony-pill blue">Tech Art</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">Unreal Engine</span>
    <span class="tony-pill black">Tools</span>
  </div>
</div>

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="ProcTex.webp" alt="ProcTex Plugin Interface" style="width: 100%; height: auto; display: block;" />
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i>Extended Highlights</h3>
  <ul>
    <li>Created a custom C++ Editor tool with <span class="keyword-red">Native UI Integration</span> directly into the main Level Editor toolbar.</li>
    <li>Added a general 3D previewer supporting both <span class="keyword-red">Static Meshes and Skeletal Meshes</span> inside a custom environment.</li>
    <li>Built responsive <span class="keyword-red">Sliding Filters</span> allowing real time adjustments to Resolution, Noise, Color Variance, and Posterization.</li>
    <li>Created a simple <span class="keyword-red">One Click Export</span> system to bake generated texture data into raw Texture Assets or readys to use Materials directly into the Content Browser.</li>
  </ul>
</div>

## Plugin Overview

ProcTex was born out of a need to rapidly iterate on retro assets during the development of SOL CONSTRUCT. Rather than bouncing back and forth between external texture editing software and the engine, I wanted a native environment to instantly create our textures.


**Core Tool Features:**

* **Live 3D & 2D Previews:** Updates applied via the UI parameters are mapped in real time to an isolated 2D canvas and a full 3D viewport.

* **Universal Mesh Support:** Use a drop down menu to assign any custom Static or Skeletal mesh to preview the texture application. 

* **Color Correction & Filters:** Swap specific colors, adjust global tint, tweak brightness, and crush saturation. The built in posterize limits color depth to achieve that authentic, chunky feel.

* **Flexible Export:** You have the choice to either export raw textures to plug into your own custom shader pipelines, or export everything packaged cleanly into a ready to use Unreal Material. 

<div class="clean-carousel">
  <img src="image2.webp" alt="ProcTex Screenshot 2">
  <img src="image3.webp" alt="ProcTex Screenshot 3">
  <img src="image4.webp" alt="ProcTex Screenshot 4">
  <img src="image5.webp" alt="ProcTex Screenshot 5">
</div>

*(Little Side note: Coincidentally, Puck's Pixelizer came out right around the time I was building this! Their tool is incredibly robust and offers a ton of advanced features, so I highly recommend checking it out if you need a heavier-duty solution, plus their palette stuff is super neat!)*

## Technical Implementation

Developing ProcTex required bridging the gap between Blueprint Editor Utility Widgets (EUWs) and C++ Editor modules to achieve a seamless, native feel. This was the first "tool" I've ever built so it was certaintly a journey trying to figure this stuff out 😅.

* **Custom 3D Viewport in UMG:** To render a live 3D mesh inside a UMG widget, I created a custom Slate viewport leveraging `SEditorViewport` and `FAdvancedPreviewScene`. This required creating a custom subclass of `FEditorViewportClient` to dynamically override the background color (matching the editor's UI hex colors) and locking Post Process exposure settings so the preview meshes wouldn't completely blow out against the dark background.

{{< code src="CustomViewport.cpp" lang="cpp" title="CustomViewportSnippet.cpp" >}}

## Overcoming Quirks with SinglePropertyViews:
Building a simple dropdown to select either a Static or Skeletal mesh ran into UE5's strict property typing. I solved this by defining a generic UObject* variable in C++ using the AllowedClasses = "StaticMesh,SkeletalMesh" specifier. To bypass UMG bugs, the widget dynamically binds to itself using an Event Pre Construct node before executing a C++ cast to seamlessly swap the hidden mesh components in the preview scene.

{{< blueprint src="TextureGeneratorGraph.txt" >}}

## Procedural Material Architecture:
The underlying retro rendering logic relies heavily on parameterized Materials all working together. The posterization effect, for instance, uses a streamlined Multiply -> Floor -> Divide math operation to snap 0-1 color values into distinct visual bands. By updating global parameters via Dynamic Material Instances, sliders in the UI recalculate the shader logic instantly.

{{< blueprint src="generatorgraph.txt" >}}