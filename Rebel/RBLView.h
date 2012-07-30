//
//  RBLView.h
//  Rebel
//
//  Created by Justin Spahr-Summers on 2012-07-29.
//  Copyright (c) 2012 GitHub. All rights reserved.
//

#import <Cocoa/Cocoa.h>

/*
 * A base class for saner and more full-featured layer-backed views.
 */
@interface RBLView : NSView

/*
 * The backing layer's background color, or nil if none has been set.
 */
@property (nonatomic, strong) NSColor *backgroundColor;

/*
 * Whether the view's drawing completely fills its bounds with opaque content.
 *
 * Defaults to NO.
 */
@property (nonatomic, getter = isOpaque) BOOL opaque;

/*
 * Whether the graphics context for the view's drawing should be cleared to
 * transparent black in RBLView's implementation of -drawRect:.
 *
 * Defaults to YES.
 */
@property (nonatomic, assign) BOOL clearsContextBeforeDrawing;

/*
 * Determines when the backing layer's contents should be redrawn.
 *
 * If -drawRect: is not overridden, this defaults to
 * NSViewLayerContentsRedrawNever. If -drawRect: is overridden, this defaults to
 * NSViewLayerContentsRedrawDuringViewResize.
 *
 * For better performance, subclasses should set the contentsCenter property of
 * the backing layer to support scaling, and then change the value of this
 * property to NSViewLayerContentsRedrawBeforeViewResize or
 * NSViewLayerContentsRedrawOnSetNeedsDisplay.
 */
@property (nonatomic, assign) NSViewLayerContentsRedrawPolicy layerContentsRedrawPolicy;

/*
 * Subclasses may override this method to redraw the given rectangle. Any
 * override of this method should invoke super.
 */
- (void)drawRect:(NSRect)rect;

/*
 * Subclasses may override this method to manually lay out subviews. Any
 * override of this method should invoke super.
 */
- (void)layout;

@end
