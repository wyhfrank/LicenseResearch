/*******************************************************************************
 * Copyright (c) 2007, 2010 David Green and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     David Green - initial API and implementation
 *******************************************************************************/

package org.eclipse.mylyn.internal.wikitext.ui.editor.syntax;

import org.eclipse.osgi.util.NLS;

/**
 * @author David Green
 */
class Messages extends NLS {
	private static final String BUNDLE_NAME = "org.eclipse.mylyn.internal.wikitext.ui.editor.syntax.messages"; //$NON-NLS-1$

	public static String FastMarkupPartitioner_0;

	public static String FastMarkupPartitioner_1;

	public static String MarkupHyperlinkDetector_openException;

	public static String MarkupHyperlinkDetector_openFileInEditor;

	public static String MarkupHyperlinkDetector_unexpectedError;

	public static String MarkupTokenScanner_2;

	public static String MarkupTokenScanner_3;

	public static String MarkupTokenScanner_badTokenLength;

	public static String MarkupTokenScanner_badTokenOffset;
	static {
		// initialize resource bundle
		NLS.initializeMessages(BUNDLE_NAME, Messages.class);
	}

	private Messages() {
	}
}
