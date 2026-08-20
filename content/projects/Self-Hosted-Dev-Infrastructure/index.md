---
title: Self Hosted Developement Environment
date: 2026-02-06
summary: Centralised Nextcloud and Perforce server environment.
tags:
  - Tools
  - Web Dev
  - Perforce
  - Nextcloud
  - Truenas
  - Cloudflared
  - NGINX
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
  Deployed a centralised Nextcloud and Perforce server environment tailored to the team's pipeline, easing asset management and establishing a reliable, autonomous version control.
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
    <span class="tony-pill blue">Cloudflared</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">NGINX</span>
    <span class="tony-pill black">TrueNAS</span>
    <span class="tony-pill black">Tools</span>
  </div>
</div>

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <a data-fancybox="gallery" href="featured.jpg" data-caption="TrueNAS Apps Interface">
  <img src="featured.jpg" alt="ProcTex Plugin Interface" style="width: 100%; height: auto; display: block;" />
    </a>
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i> Highlights</h3>
  <ul>
    <li>Built a custom <span class="keyword-red">TrueNAS & Perforce Server</span> from spare office PC parts, completely eliminating Git LFS merge nightmares and monthly cloud subscription fees.</li>
    <li>Bypassed WAN TCP limitations by chaining <span class="keyword-red">Cloudflared Tunnels with NGINX SSL</span>, granting the remote team seamless, secure access without finicky VPNs.</li>
    <li>Deployed a centralised <span class="keyword-red">Nextcloud Asset Hub</span> featuring in-browser 3D FBX inspection so the team can preview models without opening a game Engine.</li>
    <li>turned a fragile, overlapping pipeline into a <span class="keyword-red">Zero Cost Hub</span>, delivering instant version control relief and immediate access for the entire team.</li>
  </ul>
</div>

## Squashing a Bottleneck

As our project grew, our team started tripping over each other's workflows on GitHub, leading to several near miss merges and frankly very unorganised asset managment. At the same time, subscriptions like Google Drive and Google Workspace were becoming unnecessarily expensive to maintain as file counts exploded, especially if we were to expand the team in the future. It was a castle built on sand.

To minimise these bottlenecks, I built a dedicated server using spare PC parts sitting around the office, supplemented by a few cheap hardware upgrades. The goal was to create a ***single*** centralised and accessible infrastructure that gave us total control over our pipeline without ongoing software costs.

## Asset Management with TrueNAS & Nextcloud

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="TruenasApps.jpg" alt="TrueNAS Apps Interface" style="width: 100%; height: auto; display: block;" />
</div>

The foundation was built on TrueNAS hosting Nextcloud to handle general asset storage. To make local services accessible anywhere without exposing vulnerable ports raw to the internet, we implemented Cloudflared tunneling and reverse proxies.

* **Secure Remote Access:** Cloudflared tunnels forward local server ports, allowing remote team members to access TrueNAS and Nextcloud from anywhere.  

* **Workflow Integration:** Integrated browser friendly tools, such as native FBX 3D viewers, directly into Nextcloud so team members can inspect 3D assets without launching the engine.

* **Easy Storage:** Google Drive-like experience for ***zero*** monthly software fees, making asset sharing across team members immediate and organised.

Best part is, all of this is accessible in browser, which means mobile interaction is inherently supported! Let me tell you, It's a pretty cool feeling popping into the office and loading up a new asset on your phone, spinning it around, zooming in, etc. The power of GPU accleration will never not blow my mind.

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <video autoplay loop muted playsinline style="width: 100%; height: auto; display: block; margin: 0 !important;">
    <source src="FBXViewerExample.webm" type="video/webm">
  </video>
</div>

## Perforce Architecture & Routing Challenges

Deploying Perforce alongside Nextcloud proved significantly more challenging due to how Perforce handles raw TCP connections over WAN setups. This frankly took a tonne of trial and error to get right.

### The Initial Attempt: Mesh VPN

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="tailscale.webp" alt="ProcTex Plugin Interface" style="width: 100%; height: auto; display: block;" />
</div>

I initially tested routing traffic through Tailscale VPN straight to the server's home IP, allowing folks to connect "locally" via TCP on port 1666. While functional for testing, forcing an entire team to maintain active VPN tunnels was far too finicky and fragile for daily production.

### The Solution: Cloudflared + NGINX SSL

To achieve a seamless, client-side connection experience, I ended up chaining together a pipeline consisting of Server Port Forwarding, a Cloudflared TCP Tunnel, and NGINX for SSL termination. SSL Certification was truly the rotten cherry on top of such already difficult cake.
<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="NGINXproxy.webp" alt="ProcTex Plugin Interface" style="width: 100%; height: auto; display: block;" />
</div>

While routing through multiple tunnel and proxy layers introduces a minor network latency overhead, in practice we found the connection speeds feel identical to commercial cloud drives.

## Results & Workflow Impact

Building the infrastructure from scratch provided deep insight into Perforce's underlying architecture - moving far beyond basic checkout/submit mechanics to configuring Streams, Depots, Workspaces, and Revision histories.

* **No Merge issues (*yet*):** Stopped workflow collisions and merge risk caused by mismanaged Git LFS setups. 

* **Instant Adoption:** The team instantly gained a secure, central hub accessible via simple web links and standard logins, immediately becoming a part of people's daily workflows.

* **Customisable to your heart's content:** This is an environment where custom editor utilities, automation tools, and project settings can be pushed centrally to support team needs, for example this other cool project I put together 

